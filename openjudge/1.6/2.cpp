#include<cstdio>

int line[20];

int main()
{
	int h, cnt = 0;
	for (int i = 1; i <= 10; ++i)
		scanf("%d", &line[i]);

	scanf("%d", &h);
	h = h + 30;

	for (int i = 1; i <= 10; ++i)
		if(line[i] <= h)
			cnt++;

	printf("%d", cnt);

	return 0;
}
