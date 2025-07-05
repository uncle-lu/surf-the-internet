#include<cstdio>
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9') { f|=(ch=='-'); ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	x = f ? -x : x;
	return ;
}

int n;
int line[110];

int main()
{
	int T;
	read(T);
	for (int t = 1; t <= T; t++) 
	{
		read(n);
		for (int i = 1; i <= n; i++) 
			read(line[i]);

		bool flag = false;
		long long int sum_limit=0, sum=0;
		for(int i=1; i<=n; ++i)
		{
			sum += line[i];
			if(sum < sum_limit) { flag = true; break; }
			sum_limit += i;
		}

		if(!flag)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
