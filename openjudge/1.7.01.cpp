#include<cstdio>
#include<cstring>

char line[265];

int main()
{
	fgets(line, 265, stdin);

	int len = strlen(line), cnt = 0;
	for (int i = 0; i < len; ++i) {
		if(line[i] >= '0' && line[i] <= '9')
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}
