#include<cstdio>
#include<cstring>

char line[20];

int main()
{
	scanf("%s", line);
	int len = strlen(line);
	int cnt = 1, sum = 0;
	for(int i=0; i<len-1; ++i)
	{
		if(line[i] != '-')
		{
			sum = sum + (line[i] - '0') * cnt;
			cnt++;
		}
	}

	sum = sum % 11;

	if(sum == 10)
	{
		if(line[len-1] == 'X')
		{
			printf("Right");
		}
		else
		{
			line[len-1] = 'X';
			printf("%s", line);
		}
	}
	else
	{
		if(line[len-1] - '0' == sum)
		{
			printf("Right");
		}
		else
		{
			line[len-1] = sum + '0';
			printf("%s", line);
		}
	}

	return 0;
}
