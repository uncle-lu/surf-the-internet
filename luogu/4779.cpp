#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int M = 2 * 1e5 + 10;
const int N = 1e5 + 10;
struct node{
	int v, next, val;
};
struct heap_node{
	int dis, u;
	friend bool operator>(const heap_node a, const heap_node b)
	{
		return a.dis > b.dis;
	}
};
node edge[M];
int head[N], cnt, dis[N];
bool vis[N];

void add_edge(int x, int y, int val)
{
	edge[++cnt].v = y;
	edge[cnt].val = val;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

int main()
{
	memset(head, -1, sizeof(head));
	int n, m, s, x, y, val;
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> val;
		add_edge(x, y, val);
	}

	priority_queue<heap_node, vector<heap_node>, greater<heap_node> >T;

	memset(dis, 0x7f7f7f7f, sizeof(dis));
	dis[s] = 0;
	T.push({0, s});
	while(!T.empty())
	{
		int u = T.top().u;
		T.pop();
		if(vis[u])continue;
		vis[u] = true;
		for (int i=head[u]; ~i; i=edge[i].next)
			if(dis[edge[i].v] > dis[u] + edge[i].val)
			{
				dis[edge[i].v] = dis[u] + edge[i].val;
				T.push({dis[edge[i].v], edge[i].v});
			}
	}

	for (int i = 1; i <= n; ++i) {
		cout << dis[i] << ' ';
	}

	return 0;
}
