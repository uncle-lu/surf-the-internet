#include<cstdio>
#include<cstring>

char str[100][100];

int main()
{
	int t=0;
	while(~scanf("%s", str[t]))
		t++;

	for(int i=t-1; i>=0; i--)
		printf("%s", str[i]);

	return 0;
}
