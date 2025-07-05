#include<cstdio>
#include<cmath>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	bool f = false;
	for(int i=n; i<=m; ++i)
	{
		bool flag = true; // 假设i为素数
		for(int j=2; j<=sqrt(i); j++)
			if(i%j == 0)
			{
				flag = false;
				break;
			}
		if(flag)
		{
			int temp = 0, t = i;
			while(t!=0)
			{
				temp = temp*10 + t%10;
				t/=10;
			}
			for(int j=2; j<=sqrt(temp); j++)
				if(temp%j == 0)
				{
					flag = false;
					break;
				}

			if(flag)
			{
				if(f == false) f = true;
				else printf(",");
				printf("%d", i);
			}
		}
	}
	if(f == false)
		printf("No");
	return 0;
}
