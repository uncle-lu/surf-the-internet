#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int N = 100010;
vector<int>maps[N];
bool vis[N];
int n, m;

void DFS(int x)
{
	cout << x << ' ';
	for(int i=0; i<(int)maps[x].size(); i++) {
		int v = maps[x][i];
		if(vis[v])continue;
		vis[v] = true;
		DFS(v);
	}

	return ;
}

void BFS()
{
	memset(vis, false, sizeof(vis));
	queue<int>qu;
	vis[1] = true;
	qu.push(1);
	while(!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		cout << now << ' ';
		for(int i=0; i<(int)maps[now].size(); i++)
		{
			int v = maps[now][i];
			if(vis[v])continue;
			vis[v] = true;
			qu.push(v);
		}
	}

	return ;
}

int main()
{
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		maps[x].push_back(y);
	}
	for (int i = 1; i <= n; ++i)
		sort(maps[i].begin(), maps[i].end());

	vis[1] = true;
	DFS(1);
	cout << endl;
	BFS();

	return 0;
}
