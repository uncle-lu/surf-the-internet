#include<cstdio>
#include<cstring>
char line[100010];
int flag[36],n;
int main()
{
	scanf("%s", line);
	n=strlen(line);
	for(int i=0;i<n;++i)
	{
		flag[line[i]-'a'+1]++;
	}
	for(int i=0;i<n;i++)
	{
		if(flag[line[i]-'a'+1]==1)
		{
			printf("%c",line[i]);
			return 0;
		}
	}
	printf("no");
	return 0;
}
