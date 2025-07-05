#include<cstdio>
#include<cstring>

struct node{
	int x, y, t;
};
node line[160010];
bool visit[400][400];
int map[400][400];
int x_turn[5]={-1,1,0,0,0};
int y_turn[5]={0,0,1,-1,0};
int head=1, last=0, ans = -1;

void BFS(int x, int y)
{
	node now;
	line[++last] = (node){x, y, 0};
	visit[x][y] = true;

	while(head <= last)
	{
		now = line[head];
		head++;
		for(int i=0; i<4; ++i)
		{
			int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
			if(xx < 0 || xx > 400 || yy < 0 || yy > 400)continue;
			if(map[xx][yy] <= now.t + 1 && map[xx][yy] != -1)continue;
			if(visit[xx][yy])continue;
			
			if(map[xx][yy] == -1)
			{
				ans = now.t + 1;
				return ;
			}

			visit[xx][yy] = true;
			line[++last] = (node){xx, yy, now.t + 1};
		}
	}
	return ;
}

int main()
{
	memset(map,-1,sizeof(map));

	int x, y, t, n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d %d %d", &x, &y, &t);
		for(int j=0; j<=4; ++j)
		{
			int xx = x + x_turn[j], yy = y + y_turn[j];
			if(xx < 0 || xx > 400 || yy < 0 || yy > 400)continue;
			if(map[xx][yy] == -1 || map[xx][yy] > t)
				map[xx][yy] = t;
		}
	}

	BFS(0, 0);

	printf("%d", ans);
	return 0;
}
