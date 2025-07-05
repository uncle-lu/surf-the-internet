#include<cstdio>
#include<cstring>

char s[200][200];

int main()
{
	int t=0;
	while(~scanf("%s", s[t]))
		t++;

	for(int i=0; i<t; ++i)
		printf("%s ", s[i]);
	
	return 0;
}
