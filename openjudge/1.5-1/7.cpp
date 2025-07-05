#include<cstdio>

int main()
{
	long long int x;
	scanf("%lld", &x);
	int mx, mi;
	mx = x%10;
	mi = x%10;

	while(x != 0)
	{
		if(mx < x%10)
			mx = x%10;
		if(mi > x%10)
			mi = x%10;
		x/=10;
	}
	printf("%d", mx - mi);
	return 0;
}
