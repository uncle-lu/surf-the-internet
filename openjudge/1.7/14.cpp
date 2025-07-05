#include<iostream>
#include<cstring>
using namespace std;

char ch[110];

int main()
{
	cin.getline(ch, 110);
	int n = strlen(ch);
	for(int i=0;i<n;++i)
	{
		if(ch[i]>='a'&&ch[i]<='z')
			ch[i] = ch[i] - 'a' + 'A';
		else if(ch[i]>='A'&&ch[i]<='Z')
			ch[i] = ch[i] - 'A' + 'a';
	}
	printf("%s", ch);
	return 0;
}
