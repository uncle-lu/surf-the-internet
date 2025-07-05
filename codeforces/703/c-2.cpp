#include<cstdio>//uncle-lu

int ask(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);

	int temp;
	scanf("%d", &temp);
	return temp;
}

int main()
{
	int n, smax, temp;
	scanf("%d", &n);
	smax = ask(1, n);

	if(smax != 1)temp = ask(1, smax);
	if(smax != 1 && temp == smax)
	{
		int l = 1, r = smax, mid;
		while(l + 1 < r)
		{
			mid = (l+r)>>1;
			if(ask(mid, smax) == smax)
				l = mid;
			else
				r = mid;
		}

		printf("! %d", l);
	}
	else
	{
		int l = smax, r = n+1, mid;
		while(l + 1 < r)
		{
			mid = (l+r)>>1;
			if(ask(smax, mid) == smax)
				r = mid;
			else
				l = mid;
		}

		printf("! %d", r);
	}

	return 0;
}
