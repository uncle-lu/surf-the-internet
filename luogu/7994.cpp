#include<cstdio>

int n;
int line[100010];
int target[100010];
int a[100010], b[100010];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d", &target[i]);
	for(int i=1; i<=n; ++i)
		scanf("%d", &line[i]);
	for(int i=1; i<=n; ++i)
	{
		int temp = target[i] - line[i];
		if(temp < 0)
			b[i] = -temp;
		else
			a[i] = temp;
	}

	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(a[i] > a[i-1])
			ans += a[i] - a[i-1];

	for(int i=1; i<=n; ++i)
		if(b[i] > b[i-1])
			ans += b[i] - b[i-1];

	printf("%d", ans);

	return 0;
}
