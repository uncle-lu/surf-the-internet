#include<cstdio>
const int N = 1e6+10;
int line[N], n, mx;
long long int m;
bool check(long long int x) {
	long long int sum = 0;
	for(int i=1; i<=n; i++) {
		if(line[i] > x)
			sum += line[i]-x;
	}
	return sum >= m;
}
int main() {
	scanf("%d %lld", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &line[i]);
		if(mx < line[i])mx = line[i];
	}
	long long int l=0, r=mx, mid;
	while( l < r ) {
		mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid-1;
	}
	printf("%lld", l);
	return 0;
}
