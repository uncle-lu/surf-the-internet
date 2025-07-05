#include<cstdio>

int n;
char m[101][101];
bool visit[101][101];
int start_x, start_y, end_x, end_y;
int ans=-1;
int turn_x[4]={1, 0, -1, 0};
int turn_y[4]={0, 1, 0, -1};

void DFS(int x, int y, int before, int now)
{
	if(ans!=-1 && now>ans)
		return ;

	if(x == end_x && y == end_y)
	{
		if(ans == -1 || ans > now)
			ans = now;
		return ;
	}

	for(int i=0; i<4; ++i)
	{
		int xx = x + turn_x[i], yy = y + turn_y[i];
		if(xx < 1 || xx > n || yy < 1 || yy > n)
			continue;
		if(visit[xx][yy])
			continue;
		if(m[xx][yy] == 'x')
			continue;
		if(before==-1 || i%2 == before%2)
		{
			visit[xx][yy] = true;
			DFS(xx, yy, i, now);
			visit[xx][yy] = false;
		}
		else
		{
			visit[xx][yy] = true;
			DFS(xx, yy, i, now+1);
			visit[xx][yy] = false;
		}
	}

	return ;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			scanf(" %c", &m[i][j]);
			if(m[i][j]=='A')
			{
				start_x = i; start_y = j;
			}
			if(m[i][j]=='B')
			{
				end_x = i; end_y = j;
			}
		}

	DFS(start_x, start_y, -1, 0);

	printf("%d", ans);

	return 0;
}
