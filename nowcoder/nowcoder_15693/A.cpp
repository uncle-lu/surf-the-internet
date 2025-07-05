#include<cstdio>//uncle-lu
#include<algorithm>

int map[1010][1010];
int n;

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d", &map[i][j]);

	int temp = (map[1][3] + map[1][2] - map[2][3])/2;

	printf("%d ", temp);

	for(int i=2; i<=n; ++i)
		printf("%d ", map[1][i] - temp);

	return 0;
}
