#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

char line[10010];
int a[510];
const int Mod = 10000;

int binpow(int a, int b)
{
	int ans=1, temp=a;
	while(b != 0)
	{
		if( b & 1 ) ans = (ans * temp)%Mod;
		temp = (temp * temp)%Mod;
		b >>= 1;
	}

	return ans;
}

int main()
{
	a[1] = 2011;
	for(int i=2; i<=500; ++i)
	{
		a[i]=(a[i-1]*2011)%10000;
	}
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		scanf("%s", line);
		int lenth = 0, n;
		lenth = strlen(line);
		if(lenth < 4)
		{
			n = atoi(line)%500;
		}
		else
		{
			for(int i=lenth-3;i<=lenth-1;i++)
				n=n*10+line[i]-'0';
		}
		printf("%d\n", a[n%500]);
	}

	return 0;
}
