#include<cstdio>

int main()
{
	int n, cnt = 0, mx = 0, a, b;
	scanf("%d", &n);

	for(int i=1; i<=n; ++i)
	{
		scanf("%d %d", &a, &b);

		if(90 <= a && a <= 140 && 60 <= b && b <= 90)
		{
			cnt++;
			if(cnt > mx)mx = cnt;
		}
		else
		{
			cnt = 0;
		}
	}

	printf("%d", mx);
	return 0;
}
