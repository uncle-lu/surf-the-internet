#include<cstdio>

int main()
{
	int n, temp, cnt = 0;

	scanf("%d", &n);

	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &temp);
		int a = temp%10;
		int b = temp/10%10;
		int c = temp/100%10;
		int d = temp/1000%10;
		if(a - b - c - d > 0)
			cnt = cnt + 1;
	}

	printf("%d", cnt);
	return 0;
}
