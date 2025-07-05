#include<cstdio>//uncle-lu
#include<algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		
		printf("%d\n", (n-k) + (k/2));

		for(int i=n; i>=(k+1)/2; i--)
		{
			if(i==k)continue;
			printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}
