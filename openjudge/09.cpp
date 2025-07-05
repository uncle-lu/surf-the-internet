#include<cstdio>

int A[110][110], B[110][110], C[110][110];
int n, m, k;

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d", &A[i][j]);
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=k; ++j)
			scanf("%d", &B[i][j]);

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=k; ++j)
			for(int x=1; x<=m; ++x)
				C[i][j] += A[i][x] * B[x][j];

	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=k; ++j)
			printf("%d ", C[i][j]);
		printf("\n");
	}

	return 0;
}
