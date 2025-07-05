#include<cstdio>
#include<cstring>

char s[310][300];

int main()
{
	int t=0;
	while(~scanf("%s", s[t]))
		t++;

	for(int i=0; i<t; ++i)
	{
		if(i == 0)
			printf("%d", (int)strlen(s[i]));
		else
			printf(",%d", (int)strlen(s[i]));
	}

	return 0;
}
