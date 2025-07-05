#include <algorithm>
#include <cstdio> //uncle-lu
#include <cstring>
#include <queue>

struct node {
    int x, y;
};
int n, m;
int map[1010][1010];
bool visit[1010][1010];
int turn_x[4] = {1, -1, 0, 0};
int turn_y[4] = {0, 0, 1, -1};

bool check(int x) {
    memset(visit, false, sizeof(visit));
    std::queue<node> qu;
    visit[1][1] = true;
    qu.push((node){1, 1});
    while (!qu.empty()) {
        node now = qu.front();
        qu.pop();
        for (int i = 0; i <= 3; i++) {
            int xx = now.x + turn_x[i], yy = now.y + turn_y[i];
            if (map[xx][yy] > x || xx < 1 || xx > n || yy < 1 || yy > m || visit[xx][yy])
                continue;
            visit[xx][yy] = true;
            if (xx == n)
                return true;
            qu.push((node){xx, yy});
        }
    }
    return false;
}

int main() {
    int mx = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
            mx = std::max(mx, map[i][j]);
        }

    int l = 0, r = mx;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d", l);
    return 0;
}