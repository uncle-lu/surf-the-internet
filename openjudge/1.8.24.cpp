#include<cstdio>

int map[15][15];

int main()
{
	int n;
	scanf("%d", &n);

	int x=1, y=1;
	for(int i=1; i<=n*n; i++)
	{
		map[x][y] = i;

		if(y == 1 && x == n && n % 2 == 0)
			y = y + 1;
		else if(x == 1 && y == n && n % 2 == 1)
			x = x+1;
		else if(y == 1 && (x + y) % 2 == 1)
			x = x+1;
		else if(x == 1 && (x+y) % 2 == 0)
			y = y+1;
		else if(x == n && (x+y) % 2 == 1)
			y = y+1;
		else if(y == n && (x+y) % 2 == 0) 
			x = x+1;
		else if((x+y) % 2 == 1) 
		{
			x = x+1;
			y = y-1;
		}
		else if((x+y) % 2 == 0)
		{
			x = x-1;
			y = y+1;
		}
	}


	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	return 0;
}
