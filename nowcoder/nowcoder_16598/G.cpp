#include<cstdio>//uncle-lu
#include<algorithm>

int main()
{
	int n, k, sum = 0, temp;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &temp);
		sum += temp;
	}

	printf("%d.", sum/n);
	sum -= sum/n*n;

	for(int i=1; i<=k; ++i)
	{
		sum *= 10;
		printf("%d", sum/n);
		sum -= sum/n*n;
	}
	/*
	sum*=10;
	temp = sum/n;
	sum -= temp;

	int last;
	sum*=10;
	last = sum/n;
	if(last >= 5)
		temp++;

	printf("%d", temp);
	*/

	return 0;
}
