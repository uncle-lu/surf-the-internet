#include<iostream>
#include<cstring>
using namespace std;

struct node{
	int v, next;
};
node edge[10010];
int head[1010], cnt;
int line[110], mark[1010];
bool vis[1010];

void add_edge(int x, int y)
{
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x)
{
	mark[x]++;
	for(int i=head[x]; ~i; i = edge[i].next)
	{
		if(!vis[edge[i].v])
		{
			vis[edge[i].v] = true;
			DFS(edge[i].v);
		}
	}
	return ;
}

int main()
{
	int n, m, k;
	cin >> k >> n >> m;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < k; ++i) {
		cin >> line[i];
	}
	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		add_edge(x, y);
	}

	for (int i = 0; i < k; ++i) {
		memset(vis, false, sizeof(vis));
		vis[line[i]] = true;
		DFS(line[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if(mark[i] == k)
			ans++;
	}

	cout << ans;

	return 0;
}
