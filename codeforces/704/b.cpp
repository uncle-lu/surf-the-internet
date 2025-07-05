#include<cstdio>//uncle-lu
#include<algorithm>
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9') { f|=(ch=='-'); ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	x = f ? -x : x;
	return ;
}
 
int line[100010];
int tag[100010];
int n;
 
int main()
{
	int T;
	read(T);
	for (int t = 1; t <= T; t++) 
	{
		read(n);
		for (int i = 1; i <= n; i++) 
			read(line[i]);
 
		int mx=line[1], sit=1;
		for (int i = 1; i <= n; i++) 
		{
			if(line[i] > mx)
			{
				sit = i;
				mx = line[i];
			}
			tag[i] = sit;
		}
 
		sit = n;
		while(sit)
		{
			for(int i=tag[sit]; i<=sit; ++i)
				printf("%d ", line[i]);
			sit = tag[sit] - 1;
		}
		printf("\n");
	}
 
	return 0;
}
