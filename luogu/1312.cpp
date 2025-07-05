#include<cstdio>
#include<cstring>
#include<algorithm>

struct node{
	int x, y, flag;
};
node line[10];
int map[6][8];
int temp[10];
bool visit[6][8];
int n;

void update()
{
	for(int i=1; i<=5; ++i)
	{
		memset(temp, 0, sizeof(temp));
		int t = 0;
		for(int j=1; j<=7; ++j)
			if(map[i][j])
			{
				temp[++t] = map[i][j];
			}
		for(int j=1; j<=7;++j)
			map[i][j] = temp[j];
	}
	return ;
}

int remove()
{
	int cnt = 0;
	memset(visit, false, sizeof(visit));

	for(int i=1; i<=5; ++i)
		for(int j=1; j<=7; ++j)
		{
			if(i+2 <= 5 && map[i][j] == map[i+1][j] && map[i+1][j] == map[i+2][j] && map[i][j])
				visit[i][j] = visit[i+1][j] = visit[i+2][j] = true;

			if(j+2 <= 7 && map[i][j] == map[i][j+1] && map[i][j+1] == map[i][j+2] && map[i][j])
				visit[i][j] = visit[i][j+1] = visit[i][j+2] = true;
		}

	for(int i=1; i<=5; ++i)
		for(int j=1; j<=7; ++j)
			if(visit[i][j])
			{
				cnt++;
				map[i][j] = 0;
			}

	return cnt;
}

bool check()
{
	for(int i=1; i<=5; ++i)
		for(int j=1; j<=7; ++j)
			if(map[i][j])
				return false;
	return true;
}

void print()
{
	for(int i=1; i<=n; ++i)
		printf("%d %d %d\n", line[i].x-1, line[i].y-1, line[i].flag);
	return ;
}

void DFS(int x)
{
	if(x == n+1)
	{
		if(check())
		{
			print();
			exit(0);
		}
		return ;
	}

	int back[6][8];
	memcpy(back, map, sizeof(map));

	for(int i=1; i<=5; ++i)//行
	{
		for(int j=1; j<=7; ++j)//列
		{
			if(!map[i][j])continue;

			if(i<5 && map[i+1][j] != map[i][j])
			{
				std::swap(map[i+1][j], map[i][j]);
				do{ update(); }while(remove());
				line[x] = (node){i, j, 1};
				DFS(x+1);
				memcpy(map, back, sizeof(back));
			}

			if(i>1 && map[i-1][j] != map[i][j])
			{
				std::swap(map[i-1][j], map[i][j]);
				do{ update(); }while(remove());
				line[x] = (node){i, j, -1};
				DFS(x+1);
				memcpy(map, back, sizeof(back));
			}
		}
	}
	return ;
}

int main()
{
	//freopen("in","r",stdin);
	scanf("%d", &n);

	for(int i=1; i<=5; ++i)
	{
		int j=1;
		while(true)
		{
			scanf("%d", &map[i][j]);
			if(!map[i][j])break;
			j++;
		}
	}

	DFS(1);
	printf("-1");
	return 0;
}
