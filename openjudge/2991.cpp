#include<cstdio>//uncle-lu
#include<cmath>

const int Mod = 10000;
char line[210];

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
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", line);
		line[7] = '\0';
		int b = atof(line);
		int ans = binpow(2011, b);
		printf("%d\n", ans);
	}

	return 0;
}
