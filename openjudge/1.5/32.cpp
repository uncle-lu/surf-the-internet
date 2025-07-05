#include<cstdio>

int main()
{
	int n, p=1, q=2, temp;
	double sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		sum = sum + (double)q/(double)p;
		temp = p + q;
		p = q;
		q = temp;
	}
	printf("%.4lf",sum);
	return 0;
}
