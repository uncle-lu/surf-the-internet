#include<cstdio>

int main()
{
	int n = 0, k;
	scanf("%d", &k);
	double sn = 0;

	while(true)
	{
		n = n + 1;
		sn = sn + (double)1/n;
		if(sn > k)
		{
			printf("%d", n);
			return 0;
		}
	}

	return 0;
}
