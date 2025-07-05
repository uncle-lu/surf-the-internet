#include<cstdio>

long long int F[30][30][30];

long long int w(long long int a, long long int b, long long int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	if(a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	if(F[a][b][c])return F[a][b][c];

	if(a < b && b < c)
		F[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else
		F[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);

	return F[a][b][c];
}

int main()
{
	long long int a, b, c;
	while(true)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1)
			break;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
	}
	return 0;
}
