#include<cstdio>
long long int f[40][40];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	f[0][0] = 1;
	for(int i=1; i<=m; i++) {
		for(int j=0; j<n; j++) {
			f[i][j] = f[i-1][(j-1+n)%n] + f[i-1][(j+1+n)%n];
		}
	}
	printf("%lld", f[m][0]);
	return 0;
}
