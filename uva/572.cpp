#include<iostream>
#include<cstring>
using namespace std;

int n, m;
char maps[110][110];
bool vis[110][110];

void DFS(int x, int y)
{
	for (int xx=-1; xx<=1; xx++)
		for (int yy=-1; yy<=1; yy++)
		{
			if(xx+x < 1 || xx+x > n || yy+y < 1 || yy+y > m)
				continue;
			if(vis[xx+x][yy+y])continue;
			if(maps[xx+x][yy+y] != '@')continue;
			vis[xx+x][yy+y] = true;
			DFS(xx+x, yy+y);
		}

	return ;
}

int main()
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;

		int cnt = 0;
		memset(vis, false, sizeof(vis));

		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) 
				cin >> maps[i][j] ;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if(maps[i][j] == '@')
				{
					if(vis[i][j])continue;
					cnt++;
					DFS(i, j);
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}
