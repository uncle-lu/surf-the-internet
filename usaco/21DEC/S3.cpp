#include<cstdio>

const int M = 5010;
long long int F[2*M], fa[M], fb[M];

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &a, &b);
		fa[a]++;
		fb[b]++;
	}
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			F[i+j] += fa[i] * fa[j];
			F[i+j+1] -= fb[i] * fb[j];
		}
	}
	long long int sum = 0;
	for (int i = 0; i <= 2*m; ++i) {
		sum += F[i];
		printf("%lld\n", sum);
	}
	return 0;
}
