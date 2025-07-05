#include<cstdio>
#include<cstring>
#include<algorithm>

const int N = 1010;
int line_1[N], line_2[N], n;
int F[N][6*N];
int sum;

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d %d", &line_1[i], &line_2[i]);
		sum += line_1[i] + line_2[i];
	}

	memset(F, 0x7f7f7f7f, sizeof(F));

	F[1][line_1[1]] = 0;
	F[1][line_2[1]] = 1;

	for(int i=2; i<=n; ++i)
		for(int j=0; j<=6*n; ++j)
		{
			if( j - line_1[i] >= 0)
				F[i][j] = std::min(F[i][j], F[i-1][j - line_1[i]]);
			if( j - line_2[i] >= 0)
				F[i][j] = std::min(F[i][j], F[i-1][j - line_2[i]] + 1);
		}

	int ans = 0x7f7f7f7f, cha = F[0][0];
	for(int i=0; i<=sum; ++i)
		if(F[n][i] != F[0][0])
		{
			if(abs(i - (sum-i)) < cha)
			{
				cha = abs(i - (sum - i));
				ans = F[n][i];
			}
			else if(abs(i - (sum-i)) == cha)
			{
				ans = std::min(ans, F[n][i]);
			}
		}

	printf("%d", ans);
	return 0;
}
