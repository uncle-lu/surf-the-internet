#include<cstdio>

struct node{
	int x, y;
};
node line[1010];
int mapp[40][40];
bool visit[40][40];
int x_turn[4]={ 1, -1, 0, 0 };
int y_turn[4]={ 0, 0, 1, -1 };
int n, head = 1, last = 0;

void BFS(int x, int y)
{
	node now = (node){x, y};
	line[++last] = now;

	while(head <= last)
	{
		now = line[head];
		head ++;
		mapp[now.x][now.y] = 2;
		for(int i=0; i<4; ++i)
		{
			int xx = now.x + x_turn[i] , yy = now.y + y_turn[i];
			if(xx<1||xx>n||yy<1||yy>n)continue;
			if(mapp[xx][yy]!=0)continue;
			if(visit[xx][yy])continue;
			visit[xx][yy] = true;
			line[++last] = (node){xx, yy};
		}
	}

	return ;
}

int main()
{
	//freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			scanf("%d", &mapp[i][j]);
		}

	bool flag = false;
	for(int i=1; i<=n && !flag; ++i)
	{
		for(int j=1; j<=n && !flag; ++j)
		{
			if(mapp[i][j] == 0 && mapp[i-1][j] == 1 && mapp[i][j-1] == 1)
			{
				flag = true;
				BFS(i, j);
				break;
			}
		}
	}

	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			printf("%d ", mapp[i][j]);
		}
		printf("\n");
	}

	return 0;
}
