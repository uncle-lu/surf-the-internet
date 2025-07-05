#include<cstdio>
#include<cmath>

int main()
{
	int n, a, b, c, d, e, sum1 = 0, sum2 = 0;
	scanf("%d", &n);
	if(n<0)
		 n = -n;
	a = n%10;
	b = n/10%10;
	c = n/100%10;
	d = n/1000%10;
	e = n/10000;

	if(a % 2 == 0)
		sum2 = sum2 + a;
	else
		sum1 = sum1 + a;
	if(b % 2 == 0)
		sum2 = sum2 + b;
	else
		sum1 = sum1 + b;
	if(c % 2 == 0)
		sum2 = sum2 + c;
	else
		sum1 = sum1 + c;
	if(d % 2 == 0)
		sum2 = sum2 + d;
	else
		sum1 = sum1 + d;
	if(e % 2 == 0)
		sum2 = sum2 + e;
	else
		sum1 = sum1 + e;

	printf("%d\n%d", sum1, sum2);
	return 0;
}
