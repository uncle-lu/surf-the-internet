#include<iostream>
#include<cstring>
using namespace std;
char str1[90], str2[90];

int main()
{
	cin.getline(str1, 85);
	cin.getline(str2, 85);

	int len1 = strlen(str1), len2 = strlen(str2);
	for(int i=0; i<len1; i++)
		if(str1[i] >= 'A' && str1[i] <= 'Z')
			str1[i] = str1[i] - 'A' + 'a';
	for(int i=0; i<len2; i++)
		if(str2[i] >= 'A' && str2[i] <= 'Z')
			str2[i] = str2[i] - 'A' + 'a';

	if(strcmp(str1, str2) < 0)
		printf("<");
	else if(strcmp(str1, str2) > 0)
		printf(">");
	else
		printf("=");

	return 0;
}
