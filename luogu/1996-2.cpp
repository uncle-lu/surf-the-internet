#include<cstdio>
const int N = 110;
int line[N], n, m;
bool vis[N];
int main() {
	scanf("%d %d", &n, &m);
	int i = 0, cnt = 0, tot = 0;
	while(tot < n) {
		i++;
		if(i == n+1)
			i = 1;
		if(vis[i])continue;
		cnt++;
		if(cnt == m) {
			cnt = 0; tot++;
			vis[i] = true;
			printf("%d ", i);
		}
	}
	return 0;
}
