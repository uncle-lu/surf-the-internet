#include<cstdio>
#include<cstring>

char str[40];

int main()
{
	scanf("%s", str);
	int len = strlen(str);

	if(str[len-2] == 'e' && str[len-1] == 'r')
		str[len-2] = '\0';
	else if(str[len-2] == 'l' && str[len-1] == 'y')
		str[len-2] = '\0';
	else if(str[len-3] == 'i' && str[len-2] == 'n' && str[len-1] == 'g')
		str[len-3] = '\0';

	printf("%s", str);
	return 0;
}
