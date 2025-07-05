#include<cstdio>

int F[1000010];

int main()
{
	F[1] = F[2] = 1;
	for(int i=3; i<=1000000; ++i)
		F[i] = (F[i-1] + F[i-2]) % 1000;

	int n, temp; 
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &temp);
		printf("%d\n", F[temp]);
	}
	return 0;
}
