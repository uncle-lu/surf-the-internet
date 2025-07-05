#include<cstdio>
int n;
int A[20][20], B[20][20], C[20][20];

int main()
{
	freopen("in","r",stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d", &A[i][j]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d", &B[i][j]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			C[i][j] = 1;

	for(int i=1; i<=n;++i)
		for(int j=1; j<=n; ++j)
		{
			if(B[i][j] == 0)
			{
				for(int k=1; k<=n; ++k)
					if(A[i][k]==1)
						C[k][j] = 0;
			}
		}



	printf("****\n");
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}
