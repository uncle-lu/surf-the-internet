#include<cstdio>

long long int n, k, m;

bool check(long long int x) {
	long long int days = 0, q = n, y;
	while(q > 0) {
		y = q / x;
		if(y <= m) {
			days += q / m + (q % m ? 1 : 0);
			return days <= k;
		}
		long long int repeat = q % x / y + 1;
		days += repeat;
		q -= repeat * y;
	}
	return days <= k && q < 0 ;
}

int main() {
	scanf("%lld %lld %lld", &n, &k, &m);

	long long int l = 1, r = n, mid;
	while(l < r) {
		mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%lld", l);

	return 0;
}
