#include<cstdio>
#include<cstring>
char s[200][200];
int main()
{
	int t=0;
	while(~scanf("%s",s[t]))
		t++; 
	for(int i=0;i<t-2;i++)
	{
		if(strcmp(s[i],s[t-2]) == 0)
			printf("%s ",s[t-1]);
		else
			printf("%s ",s[i]);  
	}
	return 0;
}
