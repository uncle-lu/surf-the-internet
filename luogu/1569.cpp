#include<cstdio>
#include<cstring>
const int N = 1e3+10;
int line[N], sum[N], f[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &line[i]);
		sum[i] = sum[i-1] + line[i];
	}
	if(sum[n] < 0) {
		printf("Impossible");
		return 0;
	}
	memset(f, -1, sizeof(f));
	f[0] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) 
			if(sum[i] - sum[j] >= 0 && f[i] < f[j] + 1)
				f[i] = f[j] + 1;
	}
	printf("%d", f[n]);
	return 0;
}
