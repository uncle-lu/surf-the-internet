#include<cstdio>//uncle-lu
#include<cstring>

struct node{
	int x, y;
};
node line[200000];
int n, m, last, head;
int map[410][410];
bool visit[410][410];
int turn_x[10]={-2,-1,1,2,2,1,-1,-2};
int turn_y[10]={1,2,2,1,-1,-2,-2,-1};

void BFS(int x, int y)
{
	node now = (node){x, y};
	visit[x][y] = true;
	head = 1; last = 0;
	line[++last] = now;
	map[x][y] = 0;

	while(head <= last)
	{
		now = line[head++];
		for(int i=0; i<8; ++i)
		{
			int xx = now.x + turn_x[i], yy = now.y + turn_y[i];
			if(xx < 1 || xx > n || yy < 1 || yy > m)continue;
			if(map[xx][yy] != -1)continue;
			map[xx][yy] = map[now.x][now.y] + 1;
			line[++last] = (node){xx, yy};
		}
	}

	return ;
}

int main()
{
	int x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	memset(map, -1, sizeof(map));
	BFS(x, y);

	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
			printf("%-5d", map[i][j]);
		printf("\n");
	}

	return 0;
}
