#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int line[N], n, c;
bool check(int x) {
	int m=1, sum=0;
	for(int i=2; i<=n; i++) {
		if(line[i]-line[i-1]+sum < x) 
			sum += (line[i] - line[i-1]);
		else {
			m++;
			sum = 0;
		}
	}
	return c <= m;
}

int main() {
	scanf("%d %d", &n, &c);
	for(int i=1; i<=n; i++) {
		scanf("%d", &line[i]);
	}
	sort(line+1, line+1+n);
	int l = 0, r = 1e9+10, mid;
	while(l < r) {
		mid = (l + r + 1) / 2;
		if(check(mid))
			l = mid;
		else
			r = mid-1;
	}
	printf("%d", l);
	return 0;
}
