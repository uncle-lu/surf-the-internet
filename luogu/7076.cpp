#include<cstdio>

unsigned long long int temp, s, allc, ans;
int n, m, k, c, sit, cnt;

int main() {
	scanf("%d %d %d %d", &n, &m, &c, &k);
	for(int i=1; i<=n; i++) {
		scanf("%llu", &temp);
		s |= temp;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &sit, &c);
		allc |= (1ull << sit);
	}
	ans = 1;
	for(int i=0; i<k; i++) {
		if(((s>>i)&1) == 0 && ((allc>>i)&1) == 1)continue;
		ans <<= 1;
	}
	if(cnt == 0 && !n)
		puts("18446744073709551616");
	else{
		printf("%llu", ans-n);
	}
	return 0;
}
