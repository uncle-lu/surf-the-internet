#include<cstdio>//uncle-lu
#include<algorithm>
 
int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		long long int p, a, b, c;
		scanf("%lld %lld %lld %lld", &p, &a, &b, &c);
		long long int ans ;
		ans = (a - p%a)%a;
		ans = std::min(ans, (b - p%b)%b);
		ans = std::min(ans, (c - p%c)%c);
		printf("%lld\n", ans);
	}
 
	return 0;
}
