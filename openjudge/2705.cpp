#include<cstdio>
#include<cstring>

char line[110];
char ans[110];
int i, len;

bool func()
{
	i++;
	for(; i<len; ++i)
	{
		if(line[i] == '(')
		{
			int sit = i;
			if(func())
				ans[sit] = ' ';
			else
				ans[sit] = '$';
		}
		else if(line[i] == ')')
		{
			ans[i] = ' ';
			return true;
		}
		else
			ans[i] = ' ';
	}
	return false;
}

int main()
{
	//freopen("in","r",stdin);
	while(~scanf("%s", line))
	{
		memset(ans, 0, sizeof(ans));
		i = 0;
		len = strlen(line);
		for(; i<len; ++i)
		{
			if(line[i] == '(')
			{
				int sit = i;
				if(func())
					ans[sit] = ' ';
				else
					ans[sit] = '$';
			}
			else if(line[i] == ')')
				ans[i] = '?';
			else
				ans[i] = ' ';
		}
		printf("%s\n%s\n", line, ans);
	}
	return 0;
}
