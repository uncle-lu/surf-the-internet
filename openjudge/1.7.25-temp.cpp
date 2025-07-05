#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
char str[20010],max_string[110],min_string[110],temp[110];
int max_cnt,min_cnt;
int main()
{
	cin.getline(str,20001);
	int len=strlen(str), cnt=0;
	max_cnt=-1;
	min_cnt=110;
	for(int i=0;i<=len;i++)
	{
		if(str[i]==' '||str[i]==','||str[i]=='\0')
		{
			if(cnt!=0)
			{
				temp[cnt]='\0';
				if(cnt>max_cnt)
				{
					max_cnt=cnt;
					strcpy(max_string,temp);
				}
				if(cnt<min_cnt)
				{
					min_cnt=cnt;
					strcpy(min_string,temp);
				}
				cnt=0;
			}

		}
		else
		{
			temp[cnt]=str[i];
			cnt++;
		}
	}
	printf("%s\n%s",max_string,min_string);
	return 0;
}
