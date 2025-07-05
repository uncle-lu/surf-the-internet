#include<cstdio>
#include<cmath>

int main()
{
	int n, m, x;
	scanf("%d %d %d", &m, &n, &x);
	while(m <= n * x)
	{
		x -= ceil((double)m/n);
		n += m/n;
	}
	printf("%d", n);
	return 0;
}
