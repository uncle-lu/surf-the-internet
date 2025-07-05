#include<cstdio>
int main()
{
	int a;
	scanf("%d", &a);
	if(a % 4 == 0)
	{
		if((a % 100 == 0 && a % 400 != 0) || a % 3200 == 0)
		{
			printf("N");
		}
		else
		{
			printf("Y");
		}
	}
	else
	{
		printf("N");
	}
	return 0;
}
