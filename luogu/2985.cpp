#include<cstdio>
#include<cstring>
const int N = 1e4*5 + 10;
int n, d;
int line[N], ans[N];
bool check(long long int x) {
	long long int hart = 0;
	int t = 0;
	memset(ans, 0, sizeof(ans));
	for(int i=1; i<=d; i++) {
		hart /= 2;
		while(hart < x) {
			hart += line[++t];
			ans[t] = i;
			if(t > n)
				return false;
		}
	}
	while(t <= n)
		ans[++t] = d;
	return true;
}
int main() {
	scanf("%d %d", &n, &d);
	long long int sum = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d", &line[i]);
		sum += line[i];
	}
	long long int l = 0, r = sum, mid;
	while(l < r) {
		mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	printf("%lld\n", l);
	check(l);
	for(int i=1; i<=n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
