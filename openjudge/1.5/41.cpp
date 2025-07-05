#include<cstdio>//uncle-lu

int main()
{
	int r, l, cnt;
	scanf("%d%d",&l,&r);
	cnt = 0;

	for(int i=l;i<=r;++i)
	{
		int temp = i;
		while(temp)
		{
			if(temp%10 == 2)
				cnt++;
			temp /= 10;
		}
	}

	printf("%d",cnt);

	return 0;
}
