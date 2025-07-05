#include<cstdio>
const int N = 1e6+10;
struct node{
	int l, r, val;
};
node tree[N];
int cnt[N], n, ans;
bool check(int x, int y) {
	if(x == -1 && y == -1)
		return true;
	if(x == -1 || y == -1 || tree[x].val != tree[y].val)
		return false;
	if(check(tree[x].l, tree[y].r) && check(tree[x].r, tree[y].l))
		return true;
	return false;
}
void DFS(int x) {
	if(tree[x].l != -1) {
		DFS(tree[x].l);
		cnt[x] += cnt[tree[x].l];
	}
	if(tree[x].r != -1) {
		DFS(tree[x].r);
		cnt[x] += cnt[tree[x].r];
	}
	cnt[x]++;
	if(check(tree[x].l, tree[x].r)) {
		if(ans < cnt[x])ans = cnt[x];
	}
	return ;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d", &tree[i].val);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &tree[i].l, &tree[i].r);
	}
	DFS(1);
	printf("%d", ans);
	return 0;
}
