#include<cstdio>
#include<cstring>
#include<iostream>

char line[1010];

int main()
{
	std::cin.getline(line, 1001);

	int len = strlen(line);

	int cnt = 0;
	for(int i=0; i<len; ++i)
	{
		if(line[i] == ' ')
		{
			if(cnt != 0)
			{
				printf("%d,", cnt);
				cnt = 0;
			}
		}
		else
			cnt++;
	}
	printf("%d", cnt);

	return 0;
}
