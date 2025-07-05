#include<cstdio>

const int N = 40;
long long int F[N][N];
int root[N][N];

void DFS(int l, int r) {
	if(l > r)return ;
	printf("%d ", root[l][r]);
	if(l == r) return ;
	DFS(l, root[l][r] - 1);
	DFS(root[l][r] + 1, r);
	return ;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &F[i][i]);
		root[i][i] = i;
	}

	for (int len = 1; len < n; ++len) {
		for (int l = 1; l + len <= n; ++l) {
			int r = l + len;
			F[l][r] = F[l + 1][r] + F[l][l];
			root[l][r] = l;
			for (int k = l + 1; k < r; ++k) 
				if( F[l][r] < F[l][k-1] * F[k+1][r] + F[k][k]) {
					F[l][r] = F[l][k-1] * F[k+1][r] + F[k][k];
					root[l][r] = k;
				}
		}
	}

	printf("%lld\n", F[1][n]);
	DFS(1, n);
	return 0;
}
