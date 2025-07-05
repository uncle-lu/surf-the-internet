#include<cstdio>
#include<cmath>
#include<cstring>

int n, k, ans, sum;
int line[210];

bool check(int x)
{
	for(int i=2; i<=sqrt(x); ++i)
		if(x % i == 0)
			return false;
	return true;
}

void DFS(int x, int last)
{
	if(x > k)
	{
		if(check(sum)) ans++;
		return ;
	}
	for(int i=last+1; i<=n; ++i)
	{
		sum = sum + line[i];
		DFS(x+1, i);
		sum = sum - line[i];
	}
	return ;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &line[i]);
	}

	DFS(1, 0);

	printf("%d", ans);
	return 0;
}
