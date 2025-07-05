#include<cstdio>
#include<algorithm>
#include<cmath>

const int N = 110;
long long int a[N], b[N], c[N], tc, tm;
int n;

bool check(long long int mid) {
	long long int mx = std::max(0LL, mid - tm + 1), mi = std::min(tc-1, mid);
	for (int i = 0; i < n; ++i) {
		long long int k = c[i] - a[i] * tc - b[i] * (tm - mid);
		if(b[i] - a[i] < 0)
			mx = std::max(mx, (long long int)ceil((double)k / (b[i] - a[i]) ));
		else if(b[i] - a[i] > 0)
			mi = std::min(mi, (long long int)floor((double)k / (b[i] - a[i]) ));
		else if( k < 0 )
			return false;
	}
	return mx <= mi;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %lld %lld", &n, &tc, &tm);
		for (int i = 0; i < n; ++i) 
			scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
		
		long long int l=0, r=(tc+tm), mid;
		while(l < r) {
			mid = ( l + r ) / 2;
			if(check(mid))
				r = mid;
			else
				l = mid + 1;
		}
		printf("%lld\n", l);
	}
	return 0;
}
