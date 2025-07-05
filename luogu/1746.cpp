#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int x, y;
};
int dis[1010][1010];
char map[1010][1010];
int n;
int x_turn[4]={1, 0, -1, 0};
int y_turn[4]={0, 1, 0, -1};
int main() {
	memset(dis, -1, sizeof(dis));
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("\n");
		for(int j=1; j<=n; j++)
			scanf("%c", &map[i][j]);
	}
	node start, end;
	scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);
	node now = start;
	queue<node>qu;
	dis[start.x][start.y] = 0;
	qu.push(now);
	while(!qu.empty()) {
		now = qu.front(); qu.pop();
		for(int i=0; i<4; i++) {
			int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
			if(xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy]=='1')continue;
			if(dis[xx][yy] != -1)continue;
			dis[xx][yy] = dis[now.x][now.y] + 1;
			qu.push((node){xx, yy});
		}
	}
	printf("%d", dis[end.x][end.y]);
	return 0;
}
