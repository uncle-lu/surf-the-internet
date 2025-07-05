#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e4+10;
vector<int>edge[N];
int n, m, vis[N], cnt[2];
bool flag = true;
void DFS(int x) {
	for(int i=0; i<(int)edge[x].size(); i++) {
		int v = edge[x][i];
		if(vis[x] == vis[v]) {
			flag = false;
			return ;
		}
		if(vis[v] != -1)continue;
		vis[v] = !vis[x];
		cnt[vis[v]]++;
		DFS(v);
	}
	return ;
}
int main() {
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(vis, -1, sizeof(vis));
	int ans = 0;
	for(int i=1; i<=n; i++) {
		if(vis[i] != -1)continue;
		cnt[0] = 0; cnt[1] = 1;
		vis[i] = 1;
		DFS(i);
		if(!flag)break;
		ans += min(cnt[1], cnt[0]);
	}
	if(!flag)
		printf("Impossible");
	else
		printf("%d", ans);
	return 0;
}
