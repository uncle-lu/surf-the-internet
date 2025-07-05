#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 3e5+10;
int n, m;
int a[N],b[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d", &b[i]);
	}
	sort(a+1, a+1+n);
	sort(b+1, b+1+m);
	int fa=2, fb=2, cnta=1, cntb=1;
	long long int ans = 0;
	ans = a[1]*(m-1LL) + b[1]*(n-1LL);
	while(fa<=n && fb<=m) {
		if(a[fa] <= b[fb]) {
			ans += a[fa] * (long long int)(m - cntb);
			fa++;
			cnta++;
		}
		else {
			ans += b[fb] * (long long int)(n - cnta);
			fb++;
			cntb++;
		}
	}

	printf("%lld", ans);
	return 0;
}
