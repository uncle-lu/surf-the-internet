#include<cstdio>

const int N = 110;
int line[N];
double f[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &line[i]);
	f[0] = 100;
	for(int i=1; i<=n; i++) {
		f[i] = f[i-1];
		for(int j=1; j<i; j++) 
			if(f[j] * (0.01 * line[j]) / (0.01 * line[i]) > f[i])
				f[i] = f[j] * 0.01 * line[j] / (0.01 * line[i]);
	}
	double ans = 0;
	for(int i=1; i<=n; i++)
		if(ans < f[i])
			ans = f[i];
	printf("%.2lf", ans);
	return 0;
}
