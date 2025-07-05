#include<iostream>
#include<cstring>
using namespace std;

char l[100];
int n;

int main()
{
	cin.getline(l, 100);
	n = strlen(l);
	for(int i=0;i<n;++i)
	{
		if((l[i]>='a'&&l[i]<='z')||(l[i]>='A'&&l[i]<='Z'))
		{
			if(l[i]=='z')
				l[i] = 'a';
			else if(l[i]=='Z')
				l[i] = 'A';
			else
				l[i] ++;
		}
	}
	printf("%s", l);
	return 0;
}
