#include<cstdio>
#include<cstring>
#include<algorithm>

int x[1010], y[1010];
char line[1010][110];
int n,m;

int turn(char t)
{
	int temp = 0;
	if( t<='z' && t>='a')
		temp = t - 'a';
	else
		temp = t - 'A' + 26;

	return temp;
}

char turn_back(int t)
{
	if( t>=0 && t<=25)
		return t + 'a';
	else
		return t -26 + 'A';
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; ++i)
		scanf("%d %d", &x[i], &y[i]);

	for(int i=1; i<=n; ++i)
		scanf("%s", line[i]);

	for(int i=m; i>=1; i--)
	{
		int len = strlen(line[y[i]]), len_x = strlen(line[x[i]]);
		int sit = 0;

		for(int curr=0; curr<len; ++curr, sit=(sit+1)%len_x)
		{
			int a, b, c;
			c = turn(line[y[i]][curr]);
			a = turn(line[x[i]][sit]);
			b = (c + 52 - a) % 52;
			line[y[i]][curr] = turn_back(b);
		}
	}

	for(int i=1; i<=n; ++i)
		printf("%s\n", line[i]);

	return 0;
}
