#include<cstdio>
#include<cstring>

char s1[550], s2[550];

int main()
{
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	for(int i=0; i<len1; i++)
		s1[i+len1] = s1[i];
	for(int i=0; i<len2; i++)
		s2[i+len2] = s2[i];

	int ans = 0;
	for(int i=0; i<len1; i++)
		for(int j=0; j<len2; j++)
		{
			int cnt = 0;
			while(s1[i+cnt] == s2[j+cnt] && cnt<len1 && cnt<len2)
				cnt++;
			if(ans < cnt)
				ans = cnt;
		}

	printf("%d", ans);

	return 0;
}
