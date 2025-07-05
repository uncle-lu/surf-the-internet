#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 2510;
struct node{
	int v, next;
};
int n, m, k;
int val[N], dis[N][N], f[N][4];
bool vis[N];
int head[N], cnt;
node edge[20010];

void add_edge(int x, int y) {
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

void BFS(int x) {
	memset(vis, false, sizeof(vis));
	queue<int>qu;
	qu.push(x);
	vis[x] = true;
	while(!qu.empty()) {
		int now = qu.front(); qu.pop();
		if(dis[x][now] == k+1)
			continue;
		for(int i=head[now]; ~i; i = edge[i].next ) {
			int v = edge[i].v;
			if(vis[v])continue;
			dis[x][v] = dis[x][now] + 1;
			vis[v] = true;
			qu.push(v);
		}
	}
	return ;
}

int main() {
	memset(head, -1, sizeof(head));
	int x, y;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=2; i<=n; i++) {
		scanf("%d", &val[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	for(int i=1; i<=n; i++){
		BFS(i);
	}

	for(int i=2; i<=n; i++) {
		for(int j=2; j<=n; j++) {
			if(i == j) continue;
			if(dis[1][j] == 0 || dis[j][i] == 0) continue;
			if(val[j] > val[f[i][1]]) {
				f[i][3] = f[i][2]; f[i][2] = f[i][1]; f[i][1] = j;
			}
			else if(val[j] > val[f[i][2]]) {
				f[i][3] = f[i][2]; f[i][2] = j;
			}
			else if(val[j] > val[f[i][3]]) {
				f[i][3] = j;
			}
		}
	}
	int ans = 0;
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=n; j++) {
			if(i == j) continue;
			if(dis[i][j] == 0) continue;
			for( x = 1; x <= 3; x++) 
				for( y = 1; y <= 3; y++) {
					if(f[i][x] == j || f[j][y] == i || f[i][x] == f[j][y] || (!f[i][x]) || (!f[j][y])) continue;
					ans = max(ans, val[i]+val[j]+val[f[i][x]]+val[f[j][y]]);
					break;
				}
		}
	}
	printf("%d", ans);

	return 0;
}
