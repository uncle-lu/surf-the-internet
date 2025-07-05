#include<cstdio>
const int N = 1e4*8;
int sta[N], line[N], top, n;
long long int ans = 0;
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d", &line[i]);
	for(int i=1; i<=n; i++) {
		while(top > 0 && line[sta[top]] <= line[i]) {
			ans += (i-sta[top]-1);
			top--;
		}
		sta[++top] = i;
	}
	while(top > 0) {
		ans += (n-sta[top]);
		top--;
	}
	printf("%lld", ans);
	return 0;
}
