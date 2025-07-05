#include<cstdio>//uncle-lu

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; ++i)
	{
		long long int u,v;
		scanf("%lld %lld", &u, &v);
		printf("%lld %lld\n", -u*u,v*v);
	}

	return 0;
}
