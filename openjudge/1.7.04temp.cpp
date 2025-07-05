#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char list[110];
char  sl[110];
int main()
{
	scanf("%s", list);
	int n=strlen(list);
	for(int i=0;i<n-1;i++)
	{
		sl[i]=list[i] + list[i+1];
	}
	sl[n-1]=list[n-1]+list[0];
	cout<<sl;
	return 0;  
}
