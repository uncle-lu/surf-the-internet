#include<cstdio>

int main()
{
	long long int mx, mi;
	long long int a, b, c, d, e;
	scanf("%lld %lld %d %d %d", &a, &b, &c, &d, &e);
	mx = mi = a;
	if(b > mx)mx = b;
	if(b < mi)mi = b;
	if(c > mx)mx = c;
	if(c < mi)mi = c;
	if(d > mx)mx = d;
	if(d < mi)mi = d;
	if(e > mx)mx = e;
	if(e < mi)mi = e;
	printf("%d", mx - mi);
	return 0;
}
