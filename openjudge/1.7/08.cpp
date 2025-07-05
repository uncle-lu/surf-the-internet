#include<cstdio>
#include<cstring>

char ch[50];
char x,y;

int main()
{
	scanf("%s %c %c",ch,&x,&y);
	int len=strlen(ch);
	for(int i=0;i<len;i++)
		if(ch[i]==x)
			ch[i]=y;
	printf("%s",ch);
	return 0;
}
