#include<cstdio>
#include<cstring>
char str[60];
int main()
{
	scanf("%s", str);
	int len = strlen(str);
	for(int i=0; i<len; i++) // 整体向右移动3位
	{
		if((str[i] >= 'A' && str[i] <= 'W') || (str[i] >= 'a' && str[i] <= 'w'))
			str[i] = str[i] + 3;
		else if(str[i] >= 'X' && str[i] <= 'Z')
			str[i] = str[i] - 'X' + 'A';
		else if(str[i] >= 'x' && str[i] <= 'z')
			str[i] = str[i] - 'x' + 'a';
	}
	for(int i=0; i<len; i++) // 大小写互换
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		else if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
	for(int i=len-1; i>=0; i--) // 逆序输出
	{
		printf("%c", str[i]);
	}

	return 0;
}
