#include<cstdio>
#include<cstring>
int n, m, ans, sum;
int map[10][10];
int vis[10][10];
int x_turn[8]={-1, 0, 1, -1, 1, -1, 0, 1 };
int y_turn[8]={-1, -1, -1, 0, 0, 1, 1, 1 };

void DFS(int sit) {
	if(sit == n*m) {
		if(sum > ans)ans = sum;
		return ;
	}
	int x = sit/m, y = sit%m;
	if(vis[x][y] > 0) {
		DFS(sit+1);
		return ;
	}
	DFS(sit+1);
	sum += map[x][y];
	for(int i=0; i<8; i++) {
		if(x+x_turn[i] < 0 || x+x_turn[i] >= n || y+y_turn[i] < 0 || y + y_turn[i] >=m )continue;
		vis[x+x_turn[i]][y+y_turn[i]]++;
	}
	DFS(sit+1);
	sum -= map[x][y];
	for(int i=0; i<8; i++) {
		if(x+x_turn[i] < 0 || x+x_turn[i] >= n || y+y_turn[i] < 0 || y + y_turn[i] >=m )continue;
		vis[x+x_turn[i]][y+y_turn[i]]--;
	}
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ans = 0; sum = 0;
		scanf("%d %d", &n, &m);
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++) 
			for(int j=0; j<m; j++)
				scanf("%d", &map[i][j]);
		DFS(0);
		printf("%d\n", ans);
	}
	return 0;
}
