#include<cstdio>
#include<cstring>
const int N = 1e5+10;
int n;
int line[N];
long long int sum[N];
bool check(long long int x) {
	long long int temp = 0;
	int j = 1;
	for(int i=1; i<=n; i++) {

	}
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(sum, 0, sizeof(sum));
		long long int sum = 0, l, r, mid;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &line[i]);
			sum[i] = sum[i-1] + line[i];
		}
		l = 0, r = sum;
		while(l < r) {
			mid = (l + r) / 2;
			if(check(mid))
				r = mid;
			else
				l = mid+1;
		}
	}
}
