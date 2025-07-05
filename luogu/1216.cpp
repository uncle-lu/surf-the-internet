#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1010;
int F[N][N], maps[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			scanf("%d", &maps[i][j]);
	for(int i=1; i<=n; i++)
		F[n][i] = maps[n][i];
	for(int i=n-1; i>=1; i--) 
		for(int j=1; j<=i; j++)
			F[i][j] = max(F[i+1][j], F[i+1][j+1]) + maps[i][j];
	printf("%d", F[1][1]);
	return 0;
}
