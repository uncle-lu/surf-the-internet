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
int val[N], dis[N][N];
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

	int ans = 0;
	for(int A=2; A<=n; A++) 
		for(int B=2; B<=n; B++)
			for(int C=2; C<=n; C++)
				for(int D=2; D<=n; D++) {
					if(A==B || A==C || A==D || B==C || B==D || C==D) continue;
					if(dis[1][A] && dis[A][B] && dis[B][C] && dis[C][D] && dis[D][1]) {
						ans = max(ans, val[A] + val[B] + val[C] + val[D]);
					}
				}
	printf("%d", ans);
	return 0;
}
