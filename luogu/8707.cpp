#include<cstdio>
int f[40][40];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	f[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if((i % 2 == 0 && j % 2 == 0) || (i == 1 && j == 1))
				continue;
			f[i][j] = f[i-1][j] + f[i][j-1];
		}
	}
	printf("%d", f[n][m]);
	return 0;
}
