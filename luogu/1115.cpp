#include<cstdio>

const int N = 1e5*2;
int f[N], line[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &line[i]);
	int mx = line[1];
	for(int i=1; i<=n; i++) {
		if(line[i] < f[i-1] + line[i])
			f[i] = line[i] + f[i-1];
		else
			f[i] = line[i];
		if(f[i] > mx)
			mx = f[i];
	}
	printf("%d", mx);
	return 0;
}
