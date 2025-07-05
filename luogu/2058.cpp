#include<cstdio>
const int N = 1e5+10;
const int M = 1e5*3+10;
int line[M], t[N], k[N], sit[N], tong[N], qu[N];
int ans, cnt, head=1, last;
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &t[i], &k[i]);
		sit[i] = cnt+1;
		for(int j=0; j<k[i]; j++)
			scanf("%d", &line[++cnt]);
		while(head <= last && t[qu[head]] <= t[i]-86400) {
			for(int j=0; j<k[qu[head]]; j++) {
				int x = sit[qu[head]]+j;
				tong[line[x]]--;
				if(!tong[line[x]])ans--;
			}
			head++;
		}
		for(int j=0; j<k[i]; j++) {
			int x = sit[i]+j;
			tong[line[x]]++;
			if(tong[line[x]]==1)ans++;
		}
		qu[++last] = i;
		printf("%d\n", ans);
	}
	return 0;
}
