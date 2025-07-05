#include<cstdio>
#include<cstring>

char str1[210], str2[210];

int main()
{
	scanf("%s\n%s", str1, str2);
	int len1=strlen(str1), len2=strlen(str2);
	if(len1<len2)
	{
		for(int i=0; i<=len2-len1; i++)
		{
			int flag = 1;
			for(int j=0; j<len1; j++)
				if(str1[j] != str2[i+j])
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				printf("%s is substring of %s", str1, str2);
				return 0;
			}
		}
	}
	else
	{
		for(int i=0; i<=len1-len2; i++)
		{
			int flag = 1;
			for(int j=0; j<len2; ++j)
				if(str1[i+j] != str2[j])
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				printf("%s is substring of %s", str2, str1);
				return 0;
			}
		}
	}
	printf("No substring");
	return 0;
}
