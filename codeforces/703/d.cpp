#include<cstdio>
#include<algorithm>

int n, k, temp;
int line[200010];
int t[200010];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &line[i]);
		temp = std::max(temp, line[i]);
	}

	int l=0, r=temp+1, mid;
	while(r - l > 1)
	{
		mid = (l+r)>>1;
		for(int i=1; i<=n; ++i)
			if(line[i]>=mid)
				t[i] = 1;
			else
				t[i] = -1;

		for(int i=1; i<=n; ++i)
			t[i] += t[i-1];

		int mx = t[k], mn = 0;
		for(int i=k; i<=n; ++i)
		{
			mn = std::min(mn, t[i-k]);
			mx = std::max(mx, t[i] - mn);
		}
		if(mx > 0)
			l = mid;
		else
			r = mid;
	}

	printf("%d", l);
	return 0;
}
