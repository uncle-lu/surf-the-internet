#include<cstdio>

const int N = 1e6+10;
int f[N];
int main() {
	int n;
	scanf("%d", &n);
	f[0] = 1;
	for(int i=1; i<=n; i++) 
		if(i-4 >= 0)
			f[i] += f[i-4];
	for(int i=1; i<=n; i++)
		if(i-5 >= 0)
			f[i] += f[i-5];
	printf("%d", f[n]);
	return 0;
}
