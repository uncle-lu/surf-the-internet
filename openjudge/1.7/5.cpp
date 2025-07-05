#include<iostream>
#include<cstring>
using namespace std;

char str[110], ans[110];

int main()
{
	cin.getline(str, 110);
	int len = strlen(str);
	for (int i = 0; i < len-1; ++i) 
		ans[i] = str[i] + str[i+1];
	ans[len-1] = str[len-1] + str[0];
	printf("%s", ans);
	return 0;
}
