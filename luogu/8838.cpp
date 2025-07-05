#include<cstdio>
int n, k;
int a[10], b[10], ans[10];
bool flag = false;
bool vis[10];
void DFS(int x) {
	if(x > k) {
		flag = true;
		for(int i=1; i<=k; i++)
			printf("%d ", ans[i]);
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i] || b[x]>a[i])continue;
		ans[x] = i;
		vis[i] = true;
		DFS(x+1);
		vis[i] = false;
		if(flag)return ;
	}
	return ;
}
int main() {
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) 
		scanf("%d", &a[i]);
	for(int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	DFS(1);
	if(!flag)
		printf("-1");
	return 0;
}
