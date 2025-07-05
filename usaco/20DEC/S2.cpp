#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 2510;
pair<int, int>line[N];
int lt[N], rt[N];
int main() {
	int n;
	long long int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &line[i].first, &line[i].second);
	}
	sort(line+1, line+1+n);
	
	for (int i = 1; i <= n; ++i) {
		ans++;
		int ld = 0, rd = 0;
		for (int j = i-1; j >= 1; --j) {
			if(line[i].second < line[j].second) {
				ans += (rt[j] + 1) * (ld + 1);
				rd++;
				lt[j]++;
			}
			else {
				ans += (lt[j] + 1) * (rd + 1);
				ld++;
				rt[j] ++;
			}
		}
	}

	printf("%lld", ans+1);
	return 0;
}
