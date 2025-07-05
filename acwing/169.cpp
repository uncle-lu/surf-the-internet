#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100;
int line[N], n, sum, mx, cnt, len;
bool vis[N];

bool DFS(int x, int now, int front) {
	if(x > cnt)return true;
	if(now == len)return DFS(x+1, 0, 0);
	int last = 0;
	for(int i = front + 1; i <= n; i++) {
		if(vis[i] || now + line[i] > len || line[i] == last) continue;
		vis[i] = true;
		if(DFS(x, now + line[i], i)) return true;
		vis[i] = false;
		last = line[i];
		if(now == 0 || now + line[i] == len)return false;
	}
	return false;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	while(scanf("%d", &n) && n) {
		sum = 0, mx = 0;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &line[i]);
			sum += line[i]; mx = max(line[i], mx);
		}
		sort(line+1, line+1+n, cmp);
		for (len = mx; len <= sum; ++len) {
			if(sum % len) continue;
			cnt = sum / len;
			if(DFS(1, 0, 0)) {
				printf("%d\n", len);
				break;
			}
		}
	}
	return 0;
}
