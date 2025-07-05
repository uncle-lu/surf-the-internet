#include<cstdio>
const int N = 1e6+10;
int c[N][4];
int main() {
	int n, m, x, y, type, cnt=0;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d", &x, &y, &type);
		c[x][type]++;
		c[y+1][type]--;
	}
	for(int i=1; i<=n; i++) {
		c[i][1] += c[i-1][1];
		c[i][2] += c[i-1][2];
		c[i][3] += c[i-1][3];
		if(c[i][1]&&c[i][2]&&(!c[i][3]))
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}
