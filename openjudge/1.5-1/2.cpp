#include<cstdio>
#include<cmath>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	bool flag = false;

	for(int i=n; i<=m; ++i)
	{
		if((int)sqrt(i) * (int)sqrt(i) == i)
		{
			printf("%d\n", i);
			flag = true;
		}
	}

	if(flag == false)
	{
		printf("0");
	}

	return 0;
}
