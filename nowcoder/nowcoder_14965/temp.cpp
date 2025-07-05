#include<cstdio>

int main()
{
	freopen("tempin", "r", stdin);
	for(int i=1; i<=3; ++i)
	{
		for(int j=1; j<=3; ++j)
		{
			int c;
			scanf("%d", &c);
			printf("%c ", c+'a');
		}
		printf("\n");
	}
	return 0;
}
