#include<iostream>
#include<cstring>
using namespace std;

char str[510];
char temp[510];

int main()
{
	cin.getline(str, 510);
	int len = strlen(str);
	int cnt = 0;
	for(int i=0; i<=len; i++)
	{
		if(str[i] == ' ' || str[i] == '\0')
		{
			if(cnt != 0)
			{
				for(int j=cnt-1; j>=0; j--)
					printf("%c", temp[j]);
				cnt = 0;
			}
			printf(" ");
		}
		else
		{
			temp[cnt] = str[i];
			cnt++;
		}
	}

	return 0;
}
