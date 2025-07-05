#include<cstdio>
#include<cstring>
#include<algorithm>

const int N = 500010;
int n, fa[N], stack[N], top, cnt, head[N];
long long int sum[N], l[N];
char line[N];
struct node{
	int v, next;
};
node edge[N];
void add_edge(int x, int y){
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x) {
	int temp = 0;
	if(line[x] == ')' && top){
		temp = stack[top];
		l[x] = l[fa[temp]] + 1;
		-- top;
	}
	else if(line[x] == '(')
		stack[++top] = x;
	sum[x] = sum[fa[x]] + l[x];
	for(int i=head[x]; ~i; i = edge[i].next)
		DFS(edge[i].v);
	
	if(temp)
		stack[++top] = temp;
	else if(top)
		top--;
	return ;
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	scanf("%s", line+1);
	for(int i=2; i<=n; i++){
		scanf("%d", &fa[i]);
		add_edge(fa[i], i);
	}
	DFS(1);
	long long int ans = 0;
	for(int i=1; i<=n; i++)
		ans = ans xor (sum[i] * (long long int)(i));
	printf("%lld", ans);
	return 0;
}
