#include<iomanip>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[510],b[510]; // 1
int main()
{
	cin.getline(a,500); // 2
	int len=strlen(a);
	int cnt=0;
	for(int i=0;i<=len;i++)
	{
		if(a[i]==' '||a[i]=='\0') // 6
		{
			if(cnt!=0)
			{
				for(int j=cnt-1;j>=0;j--)
				{
					printf("%c",b[j]);
				}
				cnt=0; // 5
			}
			cout<<" "; // 3
		}
		else  // 4
		{
			b[cnt]=a[i];
			cnt++;
		}

	}
	return 0;
}
