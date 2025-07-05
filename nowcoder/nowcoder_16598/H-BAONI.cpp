#include<cstdio>//uncle-lu
#include<algorithm>

const int N = 1010;
int n;
long long int h[N], s[N], w[N], ans;

void DFS(int x, int H, int S, long long int W)
{
	ans = std::max(ans, W);
	if(x > n)
		return ;

	if(H > h[x] && S > s[x])
	{
		DFS(x+1, H-h[x], S-s[x], W+w[x]);
	}
	else if(S <= s[x] && H > h[x] - (S - s[x]))
	{
		DFS(x+1, H-h[x]+(S-s[x]), 0, W+w[x]);
	}
	DFS(x+1, H, S, W);

	return ;
}

int main()
{
	int H, S;
	scanf("%d %d %d", &n, &H, &S);
	for(int i=1; i<=n; ++i)
		scanf("%lld %lld %lld", &h[i], &s[i], &w[i]);

	DFS(1, H, S, 0);

	printf("%lld", ans);

	return 0;
}
