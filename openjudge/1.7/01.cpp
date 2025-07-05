#include<iostream>
#include<cstring>
using namespace std;

char str[265];

int main()
{
	cin.getline(str, 265);
	int len = strlen(str), cnt = 0;

	for (int i = 0; i < len; ++i) 
		if(str[i] >= '0' && str[i] <= '9')
			cnt++;

	printf("%d", cnt);
	return 0;
}
