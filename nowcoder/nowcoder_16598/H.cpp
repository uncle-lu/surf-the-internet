#include<cstdio>//uncle-lu
#include<algorithm>

const int N = 1010;
long long int h[N], s[N], w[N];
long long int F[310][310];
int n, H, S;

int main()
{
	scanf("%d %d %d", &n, &H, &S);
	for(int i=1; i<=n; ++i)
		scanf("%lld %lld %lld", &h[i], &s[i], &w[i]);

	for(int i=1; i<=n; ++i)
	{
		for(int j=H; j>h[i]; --j)
		{
			for(int k=S; k>=0; --k)
			{
				if(k-s[i]<=0)
				{
					if(j-h[i]+k-s[i]>0)
					{
						F[j][k] = std::max(F[j][k], F[j-h[i]+k-s[i]][0] + w[i]);
					}
				}
				else
				{
					F[j][k] = std::max(F[j][k], F[j-h[i]][k-s[i]] + w[i]);
				}
			}
		}
	}

	long long int ans = 0;
	for(int i=1;i<=H; ++i)
		for(int j=0; j<=S; ++j)
			ans = std::max(ans, F[i][j]);

	printf("%lld", ans);
	return 0;
}
