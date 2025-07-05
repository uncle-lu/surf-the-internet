#include<iostream>
#include<cstring>
using namespace std;

char line[400];
char s[310], s1[20], s2[20];

int main()
{
	cin.getline(line, 400);
	int len = strlen(line);
	int sit = 0, slen = 0, len1 = 0, len2 = 0;
	for(slen=0; sit<len && line[sit] != ','; sit++, slen++)
		s[slen] = line[sit];
	sit++;
	for(len1=0; sit<len && line[sit] != ','; sit++, len1++)
		s1[len1] = line[sit];
	sit++;
	for(len2=0; sit<=len && line[sit] != '\0'; sit++, len2++)
		s2[len2] = line[sit];

	int l = -1, r = -1;
	for(int i=0; i<slen-len1; i++)
	{
		int flag = 1;
		for(int j=0; j<len1; j++)
			if(s[i+j] != s1[j])
			{
				flag = 0;
				break;
			}
		if(flag == 1)
		{
			l = i;
			break;
		}
	}
	for(int i=slen-len2; i>=0; i--)
	{
		int flag = 1;
		for(int j=0; j<len2; j++)
			if(s[i+j] != s2[j])
			{
				flag = 0;
				break;
			}
		if(flag == 1)
		{
			r = i;
			break;
		}
	}

	if(l == -1 || r == -1 || r<=l || r < l+len1)
		printf("-1");
	else
		printf("%d", r-(l+len1));

	return 0;
}
