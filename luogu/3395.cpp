#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node {
    int x, y;
};
int t[1010][1010];
int vis[1010][1010];
int fx[4] = {0, +1, -1, 0};
int fy[4] = {-1, 0, 0, +1};
queue<node> qu;
int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        memset(t, 0x7f, sizeof(t));
        memset(vis, -1, sizeof(vis));
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n - 2; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            t[x][y] = min(t[x][y], i);
        }
        qu.push((node){1, 1});
        vis[1][1] = 0;
        bool flag = false;
        while (!qu.empty()) {
            node now = qu.front();
            qu.pop();
            if(now.x == n && now.y == n) {
                flag = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int xx = fx[i] + now.x, yy = fy[i] + now.y;
                if (xx <= 0 || yy <= 0 || xx > n || yy > n || vis[xx][yy] != -1)
                    continue;
                if (vis[now.x][now.y] + 1 > t[xx][yy])
                    continue;
                vis[xx][yy] = vis[now.x][now.y] + 1;
                if (xx == n && yy == n) {
                    flag = true;
                    break;
                }
                qu.push((node){xx, yy});
            }
        }
        if (!flag)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}