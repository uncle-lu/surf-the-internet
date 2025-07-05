#include<cstdio>
const int N = 1e5+10;
int line[N], n, k, mx;
bool check(int x) {
	int cnt = 0;
	for(int i=1; i<=n; i++)
		cnt += line[i]/x;
	return cnt >= k;
}
int main() {
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &line[i]);
		if(mx < line[i])mx = line[i];
	}
	int l = 0, r = mx, mid; 
	while( l < r ) {
		mid = (l + r + 1) / 2;
		if(check(mid)) 
			l = mid;
		else
			r = mid - 1;
	}
	printf("%d", l);
	return 0;
}
