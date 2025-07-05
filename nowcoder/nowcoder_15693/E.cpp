#include<cstdio>
#include<algorithm>

char map[510][510];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; ++i)
		{
			scanf("\n");
			for(int j=1; j<=m; ++j)
			{
				scanf("%c", &map[i][j]);
			}
		}

		if(map[1][1]== '0')
			printf("aoligei\n");
		else
			printf("call\n");

	}

	return 0;
}
