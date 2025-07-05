#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int x, y;
};
int dis[100][100];
int x_turn[12] = {-1, 1, -2, 2, -2, 2, -1, 1, 2, 2, -2, -2};
int y_turn[12] = {2, 2, 1, 1, -1, -1, -2, -2, -2, 2, -2 ,2};
void BFS(int start_x, int start_y) {
	memset(dis, -1, sizeof(dis));
	dis[start_x][start_y] = 0;
	queue<node>qu;
	qu.push((node){start_x, start_y});
	while(!qu.empty()) {
		node now = qu.front();
		qu.pop();
		for(int i=0; i<12; i++) {
			int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
			if(xx < 1 || xx > 30 || yy < 1 || yy > 30 || dis[xx][yy] != -1)
				continue;
			dis[xx][yy] = dis[now.x][now.y] + 1;
			qu.push((node){xx, yy});
		}
	}
	printf("%d\n", dis[1][1]);
	return ;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	BFS(x, y);
	scanf("%d %d", &x, &y);
	BFS(x, y);
	return 0;
}
