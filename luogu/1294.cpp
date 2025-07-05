#include<cstdio>
#include<vector>
using namespace std;
const int N = 30;
struct node{
	int v, val;
};
vector<node>edge[N];
bool vis[N];
int n, m, sum, ans;
void DFS(int x) {
	if(sum > ans)
		ans = sum;
	for(int i=0; i<(int)edge[x].size(); i++) {
		int v = edge[x][i].v;
		if(vis[v])continue;
		sum += edge[x][i].val;
		vis[v] = true;
		DFS(v);
		vis[v] = false;
		sum -= edge[x][i].val;
	}
	return ;
}
int main() {
	scanf("%d %d", &n, &m);
	int x, y, val;
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d", &x, &y, &val);
		edge[x].push_back((node){y, val});
		edge[y].push_back((node){x, val});
	}
	for(int i=1; i<=n; i++) {
		vis[i] = true;
		DFS(i);
		vis[i] = false;
	}
	printf("%d", ans);
	return 0;
}
