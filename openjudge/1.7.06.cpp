#include<cstdio>
#include<cstring>

char str[30];

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	int flag = 1;
	for(int i=0; i<len; ++i)
	{
		if( ! ((str[i]>='a' && str[i]<='z') ||
					(str[i]>='A' && str[i]<='Z') ||
					(str[i] >='0' && str[i] <='9') ||
					str[i] == '_'))
			flag = 0;
	}
	if(str[0] >= '0' && str[0] <= '9')
		flag = 0;
	if(flag == 1)
		printf("yes");
	else
		printf("no");

	return 0;
}
