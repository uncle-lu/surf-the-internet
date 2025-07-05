#include<iomanip>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[70],b[70]; 
int len,lon,f;
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	len=strlen(a);
	lon=strlen(b);
	for(int i=0;i<len;i++)
		a[i+len]=a[i];
	for(int i=0;i<lon;i++)
		b[i+lon]=b[i];
	if(lon>=len)
	{
		for(int i=0;i<=lon;i++)
		{
			f=1;
			for(int j=0;j<len;j++) // 1
			{
				if(b[i+j]!=a[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				cout<<"true";
				return 0;
			}
		}  
	}
	else if(lon<=len)
	{
		for(int i=0;i<len;i++)
		{
			f=1;
			for(int j=0;j<lon;j++)
			{
				if(a[i+j]!=b[j])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				cout<<"true";
				return 0;
			}
		}
	}  
	cout<<"false";
	return 0;
}老师，总是输出false
