#include <cstdio>
#include <cstring>

char line[100010];
int tong[30];

int main()
{
	scanf("%s", line);
	int len=strlen(line);
	char ans=0;

	for(int i=0;i<len;i++)
		tong[line[i]-'a']++;
	for(int i=0;i<len;i++)
		if(tong[line[i]-'a']==1)
		{
			ans=line[i];
			break;
		}

	if(ans!=0)
		printf("%c", ans);
	else
		printf("no");
	return 0;
}
