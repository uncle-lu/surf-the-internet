#include<cstdio>
#include<algorithm>

const int N = 2*100010;
int n;
long long int line[N];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
			scanf("%lld", &line[i]);

		if(n == 2)
			printf("%lld\n", std::max(line[1]+line[2], abs(line[1]-line[2])*2));
		else if(n == 3)
			printf("%lld\n", std::max( { line[1] * 3, line[3] * 3, (line[2] - line[1]) * 3, (line[2] - line[3]) * 3, line[1] + line[2] + line[3]}));
		else
		{
			long long int mx = 0;
			for (int i = 1; i <= n; ++i) {
				mx = std::max(line[i], mx);
			}
			printf("%lld\n", mx * n);
		}
	}

	return 0;
}
