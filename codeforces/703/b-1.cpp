#include<cstdio>
#include<algorithm>

int x[1010], y[1010];

int main()
{
	//freopen("in","r",stdin);
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
			scanf("%d %d", &x[i], &y[i]);

		if(n == 1)
		{
			printf("1\n");
			continue;
		}

		std::sort(x+1, x+1+n);
		std::sort(y+1, y+1+n);

		int s1 = (n+1)/2, s2 = (n+2)/2;
		//printf("%d %d\n", s1, s2);
		printf("%lld\n", (long long int)(x[s2]-x[s1]+1)*(y[s2]-y[s1]+1));
	}

	return 0;
}
