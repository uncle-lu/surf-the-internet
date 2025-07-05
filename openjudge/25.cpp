#include<iostream>
#include<cstring>
#include<cstdio>

char line[20010];
char temp[110];
char mx_line[110], mi_line[110];
int mx, mi;

int main()
{
	std::cin.getline(line, 20001);
	int len = strlen(line);
	mx = -1;
	mi = 110;
	int cnt = 0;
	for(int i=0; i<=len; ++i)
	{
		if(line[i] != ' ' && line[i] != ',' && line[i] != '\0')
		{
			temp[cnt] = line[i];
			cnt++;
		}
		else
		{
			if(cnt != 0)
			{
				temp[cnt] = '\0';
				if(cnt < mi)
				{
					mi = cnt;
					strcpy(mi_line, temp);
				}
				if(cnt > mx)
				{
					mx = cnt;
					strcpy(mx_line, temp);
				}
				cnt = 0;
			}
		}
	}
	printf("%s\n%s", mx_line, mi_line);
	return 0;
}
