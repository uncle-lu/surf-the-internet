#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m, ans = 0x7f7f7f7f;

void DFS(int x, int s = 0, int v = 0, int front_r = sqrt(n), int front_h = n) {
	if(x > m) {
		if(v == n)
			ans = ans > s ? s : ans;
		return ;
	}
	for (int r = min((int)floor(sqrt(n-v)), front_r-1); r >= m-x+1; r--){
		if(2*(n-v)/r + s > ans) break;
		for (int h = min((int)floor(1.0*(n-v)/(r*r)), front_h-1); h >= m-x+1; h--) {
			if(s + 2 * r * h > ans || v + r * r * h > n)
				break;
			DFS(x + 1, s + 2 * r * h + (x == 1 ? r * r : 0), v + r * r * h, r, h);
		}
	}
	return ;
}

int main() {
	scanf("%d %d", &n, &m);

	DFS(1);

	printf("%d", ans == 0x7f7f7f7f ? 0 : ans);

	return 0;
}
