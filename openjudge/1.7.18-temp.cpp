#include<iomanip>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[210],b[210]; // 1
int len,lon,f;
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	len=strlen(a);
	lon=strlen(b);
	if(len<lon)
	{
		for(int i=0;i<=lon-len;i++)
		{
			f=1;
			for(int j=0;j<len;j++) // < 
			{
				if(b[i+j]!=a[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				cout<<a<<" is substring of "<<b;
				return 0;
			}
		}  
	}
	else if(lon<=len) // 2
	{
		for(int i=0;i<=len-lon;i++)
		{
			f=1;
			for(int j=0;j<len;j++)
			{
				if(a[i+j]!=b[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				cout<<b<<" is substring of "<<a;
				return 0;
			}
		}
	}
	cout<<"No substring"; // 3
	return 0;
}
