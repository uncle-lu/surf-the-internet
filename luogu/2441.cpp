#include<cstdio>
#include<algorithm>
const int N = 200010;
int father[N];
int line[N];
int gcd(int a, int b) {
	while (b != 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int main() {
	int n, k, x, y, type;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d", &line[i]);
	for(int i=1; i<n; i++) {
		scanf("%d %d", &x, &y);
		father[y] = x;
	}
	for(int t=1; t<=k; t++) {
		scanf("%d", &type);
		if(type == 1) {
			scanf("%d", &x);
			int temp = line[x];
			while(father[x] != 0) {
				if(gcd(line[father[x]], temp) != 1) {
					printf("%d\n", father[x]);
					break;
				}
				x = father[x];
			}
			if(father[x] == 0) 
				printf("-1\n");
		}
		else {
			scanf("%d %d", &x, &y);
			line[x] = y;
		}
	}
	return 0;
}
