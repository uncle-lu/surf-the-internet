#include<cstdio>

int F[1000010];

int func(int x)
{
	if(F[x] != 0)return F[x];
	F[x] = (func(x-1) + func(x-2)) % 1000;
	return F[x];
}

int main()
{
	F[1] = F[2] = 1;
	int n, temp;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &temp);
		printf("%d\n", func(temp));
	}

	return 0;
}
