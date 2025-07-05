#include<cstdio>

int f[1010];

int Func(int x)
{
	if(f[x] != 0)return f[x];
	int sum = 1;
	for(int i=1; i<=x/2; ++i)
	{
		sum = sum + Func(i);
	}
	f[x] = sum;
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", Func(n));
	return 0;
}
