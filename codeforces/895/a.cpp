#include<cstdio>
#include<cmath>

int main() {
	int t, a, b, c;
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		scanf("%d %d %d", &a, &b, &c);
		int temp = abs(a - b);
		printf("%d\n",(int)ceil(temp / 2.0 / c));
	}
	return 0;
}
