#include<cstdio>

const int N = 1010;
int x_turn[4]={-1, 1, 0, 0};
int y_turn[4]={0, 0, -1, 1};
char maps[N][N];
int cnt[N][N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", maps[i]+1);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(maps[i][j] != 'G')continue;
			for (int t = 0; t < 4; ++t)
				if(maps[i+x_turn[t]][j+y_turn[t]] == 'C')cnt[i][j]++;
			if(cnt[i][j] > 2)
				ans++;
			else if(cnt[i][j] == 2) {
				if(maps[i-1][j] == 'C' && maps[i][j-1] == 'C' && cnt[i-1][j-1] == 2)continue;
				if(maps[i-1][j] == 'C' && maps[i][j+1] == 'C' && cnt[i-1][j+1] == 2)continue;
				ans++;
			}
		}
	}

	printf("%d", ans);
	return 0;
}
