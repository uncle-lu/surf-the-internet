#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int x, y;
};
const int N = 510, M = 1e5 + 10;
int n, m, a, b;
int vis[N][N];
int x_turn[4]={0, 0, 1, -1};
int y_turn[4]={1, -1, 0, 0};

int main() {
    memset(vis, -1, sizeof(vis));
    queue<node>qu;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i = 1; i <= a; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vis[x][y] = 0;
        qu.push((node){x, y});
    }
    while(!qu.empty())  {
        node now = qu.front();
        qu.pop();
        for(int i = 0; i < 4; i++) {
            int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] != -1)
                continue;
            vis[xx][yy] = vis[now.x][now.y] + 1;
            qu.push((node){xx, yy});
        }
    }
    for(int i = 1; i <= b; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", vis[x][y]);
    }
    return 0;
}