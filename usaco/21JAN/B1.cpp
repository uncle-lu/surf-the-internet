#include<cstdio>
#include<cstring>

const int N = 1010;
char line[N], target[N];

int main()
{
	scanf("%s\n%s", line, target);
	int len = strlen(line), tar_len = strlen(target);
	int curr = 0, i = 0, ans = 1;
	while(curr < tar_len)
	{
		while(target[curr] != line[i])
		{
			i++;
			if(i >= len)
			{
				i = 0;
				ans++;
			}
		}
		curr++;i++;
	}
	printf("%d", ans);
	return 0;
}
