#include<cstdio>
#include<cstring>

int n, k, m;
char line[1010], ans[1010];
bool vis[30];

int main() {
	int T;
	scanf("%d\n", &T);
	while(T--) {
		memset(ans, 0, sizeof(ans));
		memset(vis, false, sizeof(vis));
		scanf("%d %d %d\n%s", &n, &k, &m, line);
		int curr = -1, cnt = 0, len = 0;
		while(curr < m-1 && len < n) {
			curr++;
			if(vis[line[curr]-'a'])
				continue;
			vis[line[curr]-'a'] = true;
			cnt++;
			if(cnt == k) {
				ans[len++] = line[curr];
				cnt = 0;
				memset(vis, false, sizeof(vis));
			}
		}
		if(len == n) {
			printf("YES\n");
			continue;
		}
		int temp = 0;
		for(int i=0; i<k; i++) 
			if(!vis[i]) {
				temp = i;
				break;
			}
		while(len < n) {
			ans[len++] = 'a'+temp;
		}
		printf("NO\n%s\n", ans);
	}
	return 0;
}
