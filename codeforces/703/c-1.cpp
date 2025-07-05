#include<cstdio>//uncle-lu

int main()
{
	int n, smax, temp;
	scanf("%d", &n);
	
	printf("? %d %d\n", 1, n);
	fflush(stdout);

	scanf("%d", &smax);

	if(n==2)
	{
		printf("! %d", smax==2 ? 1 : 2);
		fflush(stdout);
		return 0;
	}


	printf("? %d %d\n", 1, smax);
	fflush(stdout);

	scanf("%d", &temp);
	if(temp == smax)
	{
		int l=1, r=smax, mid, ans=l;
		while(l < r)
		{
			mid = (l+r) >> 1;
			printf("? %d %d\n", mid, smax);
			fflush(stdout);

			scanf("%d", &temp);
			if(temp == smax)
			{
				l = mid+1;
				ans = mid;
			}
			else
				r = mid-1;
		}
		printf("! %d\n", ans);
		fflush(stdout);
	}
	else
	{
		int l=smax, r=n, mid, ans=n;
		while(l < r)
		{
			mid = (l+r) >> 1;
			printf("? %d %d\n", smax, mid);
			fflush(stdout);

			scanf("%d", &temp);
			if(temp == smax)
			{
				r = mid-1;
				ans = mid;
			}
			else
				l = mid+1;
		}
		printf("! %d\n", ans);
		fflush(stdout);
	}

	return 0;
}
