#include<cstdio>

int h[1010][1010];
int main() {
	int n, m, x1, y1, x2, y2;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		h[x1][y1]++;
		h[x2+1][y1]--;
		h[x1][y2+1]--;
		h[x2+1][y2+1]++;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) 
			h[i][j] = h[i][j] + h[i-1][j];

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			h[i][j] = h[i][j] + h[i][j-1];

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			printf("%d ", h[i][j]);
		printf("\n");
	}
	return 0;
}
