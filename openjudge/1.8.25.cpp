#include<cstdio>
#include<cstring>

int r, c, len;
char str[400];
int line[400];
int map[20][20];
int x_turn[4]={0, 1, 0, -1};
int y_turn[4]={1, 0, -1, 0};

int main()
{
	scanf("%d %d ", &r, &c);
	gets(str+1);

	len = strlen(str+1);
	for(int i=1; i<=len; ++i)
	{
		int x;
		if(str[i] == ' ')
			x = 0;
		else 
			x = str[i] - 'A' + 1;

		int sit = i*5;
		while(x != 0)
		{
			line[sit] = x % 2;
			x /= 2;
			sit--;
		}
	}

	memset(map, -1, sizeof(map));
	int x = 1, y = 1, t = 0;
	for(int i=1; i<=r*c; ++i)
	{
		map[x][y] = line[i];
		int xx = x + x_turn[t], yy = y + y_turn[t];
		if( xx < 1 || xx > r || yy < 1 || yy > c || map[xx][yy] != -1 )
		{
			t = (t + 1)%4;
			xx = x + x_turn[t];
			yy = y + y_turn[t];
		}

		x = xx;
		y = yy;
	}

	for(int i=1; i<=r; ++i)
		for(int j=1; j<=c; ++j)
			printf("%d", map[i][j]);

	return 0;
}
