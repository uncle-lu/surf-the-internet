#include<cstdio>
#include<cmath>
const int N = 5*1e5+10;
int line[N], n, a, b;
long long int sum;
bool check(long long t) {
	long long temp=0;
	for(int i=1; i<=n; i++) {
		if(line[i] >= t * a) {
			temp += ceil(1.0 * (line[i] - t*a) / b);
		}
	}
	return temp <= t;
}
int main() {
	scanf("%d %d %d", &n, &a, &b);
	for(int i=1; i<=n; i++) {
		scanf("%d", &line[i]);
		sum += line[i];
	}
	long long int l=1, r=sum, mid;
	while(l < r) {
		mid = (l + r) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%lld", l);
	return 0;
}
