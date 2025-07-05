#include  <cstdio> 
int main()
{
	int n,m;

	scanf("%d %d",&n,&m);


	for(int i=1;i<=n;++i)
	{
		int s = 1;
		for(int j=1; j<=m ; ++j)
		{
			if(i % j == 0)
				s=s*-1;
		}

		if(s==-1)
		{
			if(i==1)printf("1");
			else printf(",%d",i);
		}

	}

	return 0;
}
