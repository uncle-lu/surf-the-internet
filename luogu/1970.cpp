#include<cstdio>

const int N = 1e5+10;
int line[N], f[N][2];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &line[i]);
	f[1][1] = f[1][0] = 1;
	//1 表示上升, 0 表示下降
	for(int i=2; i<=n; i++) {
		if(line[i] > line[i-1])
			f[i][1] = f[i-1][0] + 1;
		else
			f[i][1] = f[i-1][1];
		if(line[i] < line[i-1])
			f[i][0] = f[i-1][1] + 1;
		else
			f[i][0] = f[i-1][0];
	}
	printf("%d", f[n][1] > f[n][0] ? f[n][1] : f[n][0]);
	return 0;
}
