#include<cstdio>
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	bool f = false;
	for(int i=1; i<=n; ++i)
	{
		int flag = 1;
		for(int j=1; j<=i && j<=m; ++j)
			if( i % j == 0 )
				flag = flag * -1;
		if(flag == -1)
		{
			if(f == false)
			{
				printf("%d", i);
				f = true;
			}
			else
				printf(",%d", i);
		}
	}
	return 0;
}
