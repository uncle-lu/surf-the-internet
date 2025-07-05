#include<cstdio>

int a[1010], b[1010];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i] * b[i];
	}

	printf("%d", sum);

	return 0;
}
