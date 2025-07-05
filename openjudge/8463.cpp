#include<cstdio>//uncle-lu
#include<cmath>
#include<algorithm>

long long int a, b, x, y;
int f[5][2]={{0,0},{0,0},{0,1},{1,1},{1,0}};

void turn(int i, int n)
{
    long long xn=x,yn=y;
    if(i==1)
	{
		x = yn;
		y = xn;
	}
    if(i==4)
	{
		x=pow(2,n)-1-yn;
		y=xn;
		y=pow(2,n)-1-y;
	}
	return ;
}

void find(int s, int num)
{
	if(s == 0)return ;
	long long k = pow(2, 2*(s-1));
	int i;
	for(i=1; i<=4; ++i)
		if(k*i >= num)break;
	find(s-1, num-k*(i-1));
	turn(i, s-1);
	x += pow(2, s-1) * f[i][0];
	y += pow(2, s-1) * f[i][1];

	return ;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		int n;
		scanf("%d %lld %lld", &n, &a, &b);
		long long int x1, x2, y1, y2;
		x = y = 0;
		find(n, a);
		x1 = x; y1 = y;
		x = y = 0;
		find(n, b);
		x2 = x; y2 = y;

		long long int dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))*10;
		printf("%lld\n", dis);
	}
}
