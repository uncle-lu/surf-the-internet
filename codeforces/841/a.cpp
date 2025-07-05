#include<cstdio>

int n;
long long int line[60];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d", &n);
		long long int mu = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &line[i]);
			mu *= line[i];
		}
		mu += (n-1);
		mu *= 2022;
		printf("%lld\n", mu);
	}
	return 0;
}
