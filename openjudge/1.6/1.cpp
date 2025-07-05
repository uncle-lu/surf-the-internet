#include<cstdio>

int line[110];

int main()
{
	int n, m, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &line[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= n; ++i)
		if(line[i] == m)
			cnt ++;

	printf("%d", cnt);

	return 0;
}
