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
 
int main()
{
	int a, b, k;
	read(a);read(b);read(k);
	if(b == 1)
	{
		if(k>0)
			printf("No");
		else
		{
			printf("Yes\n");
			for(int i=1; i<=a+b; ++i)
				if(i==1)
					printf("1");
				else
					printf("0");
			printf("\n");
			for(int i=1; i<=a+b; ++i)
				if(i==1)
					printf("1");
				else
					printf("0");
		}
		return 0;
	}
	if(a == 0)
	{
		if(k>0)
			printf("No");
		else
		{
			printf("Yes\n");
			for(int i=1; i<=a+b; ++i)
				printf("1");
			printf("\n");
			for(int i=1; i<=a+b; ++i)
				printf("1");
		}
		return 0;
	}
 
	if(k > a + b - 2)
	{
		printf("No");
		return 0;
	}
 
	printf("Yes\n");
	for(int i=1; i<=a+b; i++)
		if(i<=b)
			printf("1");
		else
			printf("0");
	printf("\n");
 
 
	if(k <= a)
	{
		for(int i=1; i<=a+b; i++)
		{
			if(i<b)
				printf("1");
			else if(i<b+k)
				printf("0");
			else if(i==b+k)
				printf("1");
			else
				printf("0");
		}
	}
	else
	{
		for(int i=1; i<a+b; ++i)
		{
			if(i<b-(k-a))
				printf("1");
			else if(i==b-(k-a))
				printf("0");
			else if(i<b+1)
				printf("1");
			else
				printf("0");
		}
		printf("1");
	}
 
	return 0;
}
