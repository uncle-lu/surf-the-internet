#include<cstdio>

int n;
int map[40][40];
int x_turn[4]={1, -1, 0, 0};
int y_turn[4]={0, 0, 1, -1};

void DFS(int x, int y)
{
	for(int i=0; i<4; i++)
	{
		int xx = x + x_turn[i], yy = y + y_turn[i];
		if(xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy] != 0)
			continue;
		map[xx][yy] = 2;
		DFS(xx, yy);
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			scanf("%d", &map[i][j]);
		}

	bool flag = false;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(map[i][j] == 0 && map[i-1][j] == 1 && map[i][j-1] == 1)
			{
				map[i][j] = 2;
				DFS(i, j);
				flag = true;
				break;
			}
		}
		if(flag)break;
	}

	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
