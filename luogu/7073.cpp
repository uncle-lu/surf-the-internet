#include<cstdio>
#include<cstring>
#include<cmath>
const int N = 1e6+10;
struct node{
	int type, l, r;
	bool val;
};
node tree[N];
char line[N];
int sta[N], target[N], father[N], cnt, n;
bool DFS(int x) {
	int type = abs(tree[x].type);
	if(type == 1) {
		if(tree[x].type < 0)
			tree[x].val = !tree[x].val;
		return tree[x].val;
	}
	bool l = DFS(tree[x].l), r = DFS(tree[x].r);
	if(type == 2) {
		tree[x].val = (l && r);
	}
	else if(type == 3) {
		tree[x].val = (l || r);
	}
	father[tree[x].l] = x; father[tree[x].r] = x;
	if(tree[x].type < 0)
		tree[x].val = !tree[x].val;
	return tree[x].val;
}
int main() {
	fgets(line, sizeof(line), stdin);
	int len = strlen(line), top = 0, x;
	for(int i=0; i<len; i++) {
		if(line[i] == ' ' || line[i] == '\n')continue;
		if(line[i] == 'x') {
			int temp = 0;
			do {
				i++;
				temp = temp * 10 + line[i]-'0';
			} while(line[i+1] != ' ');
			target[temp] = ++cnt;
			sta[++top] = cnt;
			tree[cnt].type = 1;
		}
		else if(line[i] == '!') {
			tree[sta[top]].type *= -1;
		}
		else if(line[i] == '&') {
			cnt++;
			tree[cnt].type = 2;
			tree[cnt].l = sta[top]; tree[cnt].r = sta[top-1];
			top--;
			sta[top] = cnt;
		}
		else if(line[i] == '|') {
			cnt++;
			tree[cnt].type = 3;
			tree[cnt].l = sta[top]; tree[cnt].r = sta[top-1];
			top--;
			sta[top] = cnt;
		}
	}
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		tree[target[i]].val = x == 1 ? true : false;
	}
	bool ans = DFS(cnt);
	int q;
	scanf("%d", &q);
	for(int i=1; i<=q; i++){
		scanf("%d", &x);
		x = target[x];
		bool flag = false;
		while(x != cnt) {
			if(tree[father[x]].l == x && abs(tree[father[x]].type)==2 && tree[tree[father[x]].r].val == false) {
				flag = true;
				break;
			}
			if(tree[father[x]].r == x && abs(tree[father[x]].type)==2 && tree[tree[father[x]].l].val == false) {
				flag = true;
				break;
			}
			if(tree[father[x]].l == x && abs(tree[father[x]].type)==3 && tree[tree[father[x]].r].val == true) {
				flag = true;
				break;
			}
			if(tree[father[x]].r == x && abs(tree[father[x]].type)==3 && tree[tree[father[x]].l].val == true) {
				flag = true;
				break;
			}
			x = father[x];
		}
		printf("%d\n", flag ? ans: !ans);
	}
	return 0;
}
