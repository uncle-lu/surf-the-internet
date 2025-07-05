#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1010;
int line[N];

int main() {
	int n, k, ans = 0, mx = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &line[i]);
		mx = max(line[i], mx);
	}

	for (int w = 1; w <= mx; ++w) {
		priority_queue<int>qu;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			cnt += line[i] / w;
			qu.push(line[i]%w);
		}

		if(cnt >= k) {
			ans = max(ans, k / 2 * w);
		}
		else if(cnt >= k/2) {
			int ans_temp = (cnt - k / 2) * w;
			for (int temp = 0; temp < k-cnt; ++temp){
				ans_temp += qu.top();
				qu.pop();
			}
			ans = max(ans, ans_temp);
		}
	}

	printf("%d", ans);

	return 0;
}
