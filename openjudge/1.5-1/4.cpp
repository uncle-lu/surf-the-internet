#include<cstdio>

int main()
{
	long long int x;
	scanf("%lld", &x);
	int ji = 0, ou = 0;
	while(x != 0)
	{
		if(x%10%2 == 0)
			ou = ou + x%10;
		else
			ji = ji + x%10;
		x/=10;
	}
	printf("%d\n%d", ou, ji);
	return 0;
}
