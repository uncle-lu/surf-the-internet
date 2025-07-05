#include<cstdio>
#include<cstring>

int n, k, ans;
char map[100][100];
int x_turn[2]={1, 0};
int y_turn[2]={0, 1};

void DFS(int x, int y, int c, int turn)
{
	if(c == k && x != n && y != n)return ;
	if(x == n && y == n)
	{
		ans ++;
		return ;
	}

	if(map[x + x_turn[turn]][y + y_turn[turn]] == '.')
	{
		DFS(x+x_turn[turn], y+y_turn[turn], c, turn);
	}
	if(c < k && (x != 1 || y != 1) && map[x + x_turn[!turn]][y + y_turn[!turn]] == '.')
	{
		DFS(x+x_turn[!turn], y+y_turn[!turn], c+1, !turn);
	}

	return ;
}

int main()
{
	//freopen("in","r",stdin);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		memset(map, 0 ,sizeof(map));
		scanf("%d %d\n", &n, &k);
		for(int i=1; i<=n; ++i)
			scanf("%s\n", map[i]+1);

		DFS(1, 1, 0, 0);
		DFS(1, 1, 0, 1);

		printf("%d\n", ans);
	}

	return 0;
}
