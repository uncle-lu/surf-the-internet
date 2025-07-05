#include<cstdio>
#include<cmath>

int main()
{
	long long int x;
	scanf("%lld", &x);
	if((int)sqrt(x) * (int)sqrt(x) == x)
	{
		long long int temp = 0;
		while(x != 0)
		{
			temp = temp*10 + x%10;
			x/=10;
		}
		printf("%lld", temp);
	}
	else
	{
		printf("%lld", x);
	}

	return 0;
}
