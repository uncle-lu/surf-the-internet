#include<iostream>
#include<cstring>
using namespace std;

int n, m;
char maps[110][110];
bool vis[110][110];
int x_turn[8]={-1, -1, -1, 0, 0,  1, 1, 1};
int y_turn[8]={-1, 1, 0, -1, 1, -1, 1, 0};

void DFS(int x, int y)
{
	for (int i = 0; i < 8; ++i) {
		int xx = x+x_turn[i], yy = y+y_turn[i];
		if(xx < 1 || xx > n || yy < 1 || yy > m)
			continue;
		if(vis[xx][yy])continue;
		if(maps[xx][yy] != 'W')continue;
		vis[xx][yy] = true;
		DFS(xx, yy);
	}
	return ;
}

int main()
{
	cin >> n >> m;

	int cnt = 0;
	memset(vis, false, sizeof(vis));

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			cin >> maps[i][j] ;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(maps[i][j] == 'W')
			{
				if(vis[i][j])continue;
				cnt++;
				DFS(i, j);
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
