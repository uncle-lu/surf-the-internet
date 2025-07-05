#include<cstdio>
#include<cstring>
#include<algorithm>

int n, m;
int start_x, start_y, end_x, end_y;
int mx;
char map[210][210];
bool visit[210][210];
int turn_x[4]={1,-1,0,0};
int turn_y[4]={0,0,1,-1};

void DFS(int x, int y, int t)
{
	if(x == end_x && y == end_y)
	{
		mx = std::min(t, mx);
		return ;
	}

	if(mx < t)
		return ;

	for(int i=0; i<4; ++i)
	{
		int xx = x + turn_x[i], yy = y + turn_y[i];

		if(xx >= n || xx < 0 || yy < 0 || yy >= m || visit[xx][yy] || map[xx][yy] == '#')
			continue;

		visit[xx][yy] = true;
		DFS(xx, yy, t + (map[xx][yy] == 'x' ? 2 : 1) );
		visit[xx][yy] = false;
	}

	return ;
}

int main()
{
	//freopen("in", "r", stdin);
	int s;
	scanf("%d", &s);
	while(s--)
	{
		scanf("%d %d\n", &n, &m);
		for(int i=0; i<n; ++i)
			scanf("%s", map[i]);

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
			{
				if(map[i][j]=='r') { start_x = i; start_y = j; }
				if(map[i][j]=='a') { end_x = i; end_y = j; }
			}

		mx = 0x7f7f7f7f;
		memset(visit, 0, sizeof(visit));
		DFS(start_x, start_y, 0);

		if(mx != 0x7f7f7f7f)
			printf("%d\n", mx);
		else
			printf("Impossible\n");
	}

	return 0;
}
