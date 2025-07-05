#include<cstdio>
const int N = 1e6+10;
int n, k, line[N], sum[N];
int main() {
	scanf("%d\n%d", &n, &k);
	for(int i=1; i<=n; i++) {
		scanf("%d", &line[i]);
		sum[i] = sum[i-1] + line[i];
	}
	int mx = sum[k];
	for(int i=k+1; i<=n; i++) 
		if(sum[i] - sum[i-k-1] > mx)
			mx = sum[i] - sum[i-k-1];
	printf("%d", mx);
	return 0;
}
