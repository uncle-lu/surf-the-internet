#include<cstdio>

int n, H_sit, G_sit;
char line[500010];
int front[500010], behind[500010];

int main()
{
	scanf("%d", &n);
	scanf("%s", line+1);

	H_sit = G_sit = 0;
	for(int i=1; i<=n; ++i)
	{
		if(line[i] == 'H')
		{
			front[i] = H_sit;
			H_sit = i;
		}
		else
		{
			front[i] = G_sit;
			G_sit = i;
		}
	}

	H_sit = G_sit = n+1;
	for(int i=n; i>=1; --i)
	{
		if(line[i] == 'H')
		{
			behind[i] = H_sit;
			H_sit = i;
		}
		else
		{
			behind[i] = G_sit;
			G_sit = i;
		}
	}

	long long int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		//printf("%d %d\n", i, (behind[i] - i - 1) * (i - front[i] - 1) );
		ans += 1LL * (behind[i] - i - 1) * (i - front[i] - 1);
		if((behind[i] - i - 1) >= 2)
		{
			ans += behind[i] - i - 1 - 1;
		}

		if(i - front[i] - 1 >= 2)
		{
			ans += i - front[i] - 1 - 1;
		}
	}

	printf("%lld", ans);

	return 0;
}
