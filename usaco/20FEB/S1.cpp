#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5+1;

int line[N], temp[N], ans[N];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
	{
		line[i] = i;
		temp[i] = i;
		ans[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		for (int j = 0; j < (r - l + 1) / 2; j++) {
			swap(line[l+j], line[r-j]);
		}
	}

	while(k) {
		if(k & 1) {
			for (int i = 1; i <= n; ++i) {
				temp[i] = ans[line[i]];
			}
			memcpy(ans, temp, sizeof(ans));
		}
		for (int i = 1; i <= n; ++i) {
			temp[i] = line[line[i]];
		}
		memcpy(line, temp, sizeof(line));
		k >>= 1;
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
