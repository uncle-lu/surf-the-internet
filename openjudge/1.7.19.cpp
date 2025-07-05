#include<cstdio>
#include<cstring>

char str1[70], str2[70];

int main()
{
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	for(int i=0; i<len1; i++)
		str1[i+len1] = str1[i];
	for(int i=0; i<len2; i++)
		str2[i+len2] = str2[i];

	if(len1 >= len2)
	{
		for(int i=0; i<len1; i++)
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
				printf("true");
				return 0;
			}
		}
	}
	else{
		for(int i=0; i<len2; i++)
		{
			int flag = 1;
			for(int j=0; j<len1; ++j)
				if(str1[j] != str2[i+j])
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				printf("true");
				return 0;
			}
		}
	}
	printf("false");
	return 0;
}
