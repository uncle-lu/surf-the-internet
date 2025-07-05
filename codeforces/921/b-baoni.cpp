#include<cstdio>
int main() {
	int T, n, x;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &x, &n);
		int temp = x / n;
		while(x % temp != 0)
			temp--;
		printf("%d\n", temp);
	}
	return 0;
}
