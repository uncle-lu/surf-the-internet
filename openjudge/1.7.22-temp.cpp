#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
char myemail[60],a[60],b[60],c[60]; // 1
int n, flag;
int main()
{
	scanf("%s",myemail); // 2
	scanf("%d",&n);
	flag=false;
	for(int i=1;i<=n;i++) // 3
	{
		scanf("%s%s%s",a,b,c);
		if(strcmp(myemail,c)==0)
		{
			flag=true;
			int len=strlen(b);
			for(int j=0;j<len;j++)
			{
				if(b[j]>='a' && b[j]<='z') // 4
					b[j]=b[j]-'a'+'A';
				else if(b[j]>='A' && b[j]<='Z')
					b[j]=b[j]-'A'+'a';
			}
			printf("%s %s\n",a,b); // 5
		}
	}
	if(flag==false)
	{
		printf("empty");
	}
	else
	{
		printf("%s",c);
	}
	return 0;
}
