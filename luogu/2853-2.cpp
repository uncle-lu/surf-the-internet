#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1010;
vector<int>maps[N];
int cnt[N], n, m, k, line[N];
bool vis[N];

void DFS(int x)
{
	cnt[x]++;
	for(int v : maps[x])
	{
		if(vis[v])continue;
		vis[v] = true;
		DFS(v);
	}
	return ;
}

int main()
{
	cin >> k >> n >> m;
	for (int i = 0; i < k; ++i) 
		cin >> line[i];
	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		maps[x].push_back(y);
	}
	for (int i = 0; i < k; ++i) {
		memset(vis, false, sizeof(vis));
		vis[line[i]] = true;
		DFS(line[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		if(cnt[i] == k)
			ans ++;

	cout << ans;
	return 0;
}
