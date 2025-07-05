#include<cstdio>
#include<cstring>

struct node{
	int x, y, step;
};
node line[500];
int head, last;
int n, m;
char map[30][30];
bool visit[30][30];
int x_turn[4]={ -1, 1, 0, 0 };
int y_turn[4]={ 0, 0, -1, 1 };

int BFS(int start_x, int start_y)
{
	head = last = 1;
	line[head] = (node){start_x, start_y, 0};
	visit[start_x][start_y] = true;
	while(head <= last)
	{
		node now = line[head];
		head++;
		for(int i=0; i<4; ++i)
		{
			int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
			if(xx < 1 || xx > n || yy < 1 || yy > m)continue;
			if(visit[xx][yy])continue;
			if(map[xx][yy] == '#')continue;

			if(map[xx][yy] == '*'){
				return now.step + 1;
			}

			visit[xx][yy] = true;
			last++;
			line[last] = (node){ xx, yy, now.step + 1 };
		}
	}

	return -1;
}

int main()
{
	while(true)
	{
		memset(visit, false, sizeof(visit));
		int start_x, start_y;

		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)break;
		for(int i=1; i<=n; ++i)
		{
			scanf("\n");
			for(int j=1; j<=m; ++j)
			{
				scanf("%c", &map[i][j]);
				if(map[i][j] == '@')
				{
					start_x = i;
					start_y = j;
				}
			}
		}

		printf("%d\n", BFS(start_x, start_y));
	}

	return 0;
}
