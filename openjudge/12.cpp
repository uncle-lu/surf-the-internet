#include<cstdio>

char A[20][20], B[20][20];
int n;
bool flag;

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf(" %c", &A[i][j]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf(" %c", &B[i][j]);
	// ***** => 1
	flag = true;
	for(int i=1; i<=n && flag; ++i)
		for(int j=1; j<=n && flag; ++j)
			if(A[i][j] != B[j][n-i+1])
				flag = false;
	if(flag)
	{
		printf("1");
		return 0;
	}

	// ***** => 2
	flag = true;
	for(int i=1; i<=n && flag; ++i)
		for(int j=1; j<=n && flag; ++j)
			if(A[i][j] != B[n-j+1][i])
				flag = false;
	if(flag)
	{
		printf("2");
		return 0;
	}

	// ***** => 3
	flag = true;
	for(int i=1; i<=n && flag; ++i)
		for(int j=1; j<=n && flag; ++j)
			if(A[i][j] != B[n-i+1][n-j+1])
				flag = false;
	if(flag)
	{
		printf("3");
		return 0;
	}

	// ***** => 4
	flag = true;
	for(int i=1; i<=n && flag; ++i)
		for(int j=1; j<=n && flag; ++j)
			if(A[i][j] != B[i][j])
				flag = false;
	if(flag)
	{
		printf("4");
		return 0;
	}
	
	printf("5");
	return 0;
}
