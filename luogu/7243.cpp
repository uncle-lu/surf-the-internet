#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int x, y, val;
};
const int N = 2010;
long long int maps[N][N];
bool vis[N][N];
int x_turn[4]={1, 0, -1, 0};
int y_turn[4]={0, 1, 0, -1};
long long int gcd(long long int a, long long int b) {
	while(b != 0) {
		long long int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int main() {
	int n, m;
	node start;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%lld", &maps[i][j]);
	scanf("%d %d", &start.x, &start.y);
	if(maps[start.x][start.y] == 1) {
		printf("0");
		return 0;
	}
	start.val = 0;
	long long int sum = maps[start.x][start.y];
	queue<node>qu;
	qu.push(start);
	vis[start.x][start.y] = true;
	while(!qu.empty()) {
		node now = qu.front();
		qu.pop();
		for(int i=0; i<4; i++) {
			int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
			if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy])continue;
			vis[xx][yy] = true;
			sum = gcd(sum, maps[xx][yy]);
			qu.push((node){xx, yy, now.val + 1});
			if(sum == 1) {
				printf("%d", now.val + 1);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}
