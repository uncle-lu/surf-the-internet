#include<cstdio>
#include<cstring>

char line[110], t[110];

int main()
{
	scanf("%s", line);
	int len = strlen(line);
	for(int i=0; i<len; i++)
	{
		t[len-i-1] = line[i];
	}
	for(int i=0; i<len; ++i)
	{
		if(line[i] != t[i])
		{
			printf("no");
			return 0;
		}
	}

	printf("yes");
	return 0;
}
