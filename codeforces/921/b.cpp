#include<cstdio>
#include<cmath>
int main() {
	int T, n, x;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &x, &n);
		int ans = 1;
		for(int i=sqrt(x); i>=1; i--) {
			if(x%i==0) {
				if(n <= x/i && ans < i)
					ans = i;
				if(n <= i && ans < x/i)
					ans = x/i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
