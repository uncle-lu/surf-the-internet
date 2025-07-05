#include<cstdio>//uncle-lu
#include<cstring>
#include<algorithm>

char str[110];
char temp[110];
int set = 1;

void ceng(int x)
{
	for(int i=1; i<=x; ++i)
		printf("|     ");
	return ;
}

void func(int x)
{
	scanf("%s", str);
	if(x == 0 && str[0] != '#')
	{
		printf("DATA SET %d:\n", set);
		printf("ROOT\n");
	}
	if(str[0] == '#')
		exit(0);
	char line[40][110];
	int cnt = 0;
	while(true)
	{
		if(str[0] == 'f')
			strcpy(line[++cnt], str);
		else if(str[0] == 'd')
		{
			ceng(x+1);
			printf("%s\n",str);
			func(x+1);
		}
		else if(str[0] == ']' || str[0] == '*' )
		{
			for(int i=1; i<=cnt; ++i)
				for(int j=1; j<=cnt - i; ++j)
					if(strcmp(line[j], line[j+1]) > 0)
					{
						strcpy(temp, line[j]);
						strcpy(line[j], line[j+1]);
						strcpy(line[j+1], temp);
					}
			for(int i=1; i<=cnt; ++i)
			{
				ceng(x);
				printf("%s\n", line[i]);
			}
			break;
		}
		scanf("%s", str);
	}
	return ;
}

int main()
{
	while( true )
	{
		func(0);
		printf("\n");
		set++;
	}
	return 0;
}
