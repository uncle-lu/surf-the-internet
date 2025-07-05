#include<cstdio>

const int N = 210;
int f[N], maps[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		for(int j=i+1; j<=n; j++)
			scanf("%d", &maps[i][j]);
	for(int i=2; i<=n; i++) {
		f[i] = maps[1][i];
		for(int j=2; j<=i; j++)
			if(f[i] > f[j] + maps[j][i])
				f[i] = f[j] + maps[j][i];
	}
	printf("%d", f[n]);
	return 0;
}
