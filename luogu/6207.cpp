#include<cstdio>

int n, m;
char maps[120][80];
bool vis[120][80];
int x_turn[4] = {-1, 0, 1, 0};
int y_turn[4] = {0, -1, 0, 1};
int ans_x[100010], ans_y[100010], cnt;
bool flag;
void DFS(int x, int y) {
	if(x == n && y == m) {
		for(int i=1; i<=cnt; i++)
			printf("%d %d\n", ans_x[i], ans_y[i]);
		flag = true;
		return ;
	}
	for(int i=0; i<4; i++) {
		int xx = x + x_turn[i], yy = y + y_turn[i];
		if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || maps[xx][yy]=='*')continue;
		vis[xx][yy] = true;
		ans_x[++cnt] = xx; ans_y[cnt] = yy;
		DFS(xx, yy);
		cnt--;
		if(flag) return ;
	}
	return ;
}
int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("\n");
		for(int j=1; j<=m; j++)
			scanf("%c", &maps[i][j]);
	}
	vis[1][1] = true;
	cnt = 1;
	ans_x[1] = 1; ans_y[1] = 1;
	DFS(1, 1);
	return 0;
}
