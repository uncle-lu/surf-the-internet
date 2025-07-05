#include<cstdio>
const int N = 1e5+10;
long long int line[N], sum[N], ans;
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lld", &line[i]);
		sum[i] = sum[i-1] + line[i];
		if(sum[i] > 0 && i != 1)
			ans += sum[i];
	}
	printf("%lld", ans);
	return 0;
}
