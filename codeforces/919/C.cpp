#include<cstdio>
#include<cmath>
#include<algorithm>
#include<numeric>
using namespace std;
const int N = 1e5*2+10;
int line[N];

void solve() {
	int n, ans = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &line[i]);
	for(int i=1; i<=n; i++) {
		if(n % i != 0)continue;
		int g = 0;
		for(int j=1; j+i<=n;j++) {
			g = gcd(g, (int)abs(line[j] - line[j+i]));
		}
		ans += (g != 1);
	}
	printf("%d\n", ans);
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		solve();
	}
	return 0;
}
