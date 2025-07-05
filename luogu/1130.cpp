#include<cstdio>

const int N = 2010;
int f[N][N], map[N][N];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) 
		for(int j=1; j<=n; j++) 
			scanf("%d", &map[i][j]);
	for(int i=1; i<=m; i++)
		f[i][1] = map[i][1];

	for(int i=2; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			f[j][i] = f[j][i-1] + map[j][i];
			if(j != 1 && f[j-1][i-1] + map[j][i] < f[j][i])
				f[j][i] = f[j-1][i-1] + map[j][i];
			if(j == 1 && f[m][i-1] + map[j][i] < f[j][i])
				f[j][i] = f[m][i-1] + map[j][i];
		}
	}
	int ans = f[1][n];
	for(int i=2; i<=m; i++)
		if(f[i][n] < ans)
			ans = f[i][n];
	printf("%d", ans);
	return 0;
}
