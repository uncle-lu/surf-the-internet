#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 60;
struct node {
    int x, y, turn;
} start, end;
int n, m;
int maps[N][N];
int vis[N][N][4];
int x_turn[4] = {1, 0, -1, 0};
int y_turn[4] = {0, -1, 0, 1};

bool check(int x, int y, int turn) {
    if (x < 1 || x >= n || y < 1 || y >= m)
        return false;
    if (maps[x][y] || maps[x + 1][y + 1] || maps[x][y + 1] || maps[x + 1][y])
        return false;
    return true;
}

int main() {
    memset(vis, 0x7f, sizeof(vis));
    char start_turn;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &maps[i][j]);
    scanf("%d %d %d %d %c", &start.x, &start.y, &end.x, &end.y, &start_turn);
    if (start_turn == 'E')
        start.turn = 3;
    else if (start_turn == 'S')
        start.turn = 0;
    else if (start_turn == 'W')
        start.turn = 1;
    else
        start.turn = 2;

    std::queue<node> qu;
    vis[start.x][start.y][start.turn] = 0;
    qu.push(start);
    while (!qu.empty()) {
        node now = qu.front(), temp;
        qu.pop();
        if (now.x == end.x && now.y == end.y)
            break;
        for (int i = 1; i <= 3; i++) {
            temp = now;
            temp.x += x_turn[now.turn] * i;
            temp.y += y_turn[now.turn] * i;
            if (check(temp.x, temp.y, temp.turn)) {
                if (vis[temp.x][temp.y][temp.turn] != 0x7f7f7f7f)
                    continue;
                vis[temp.x][temp.y][temp.turn] = vis[now.x][now.y][now.turn] + 1;
                qu.push(temp);
            } else
                break;
        }
        if (check(now.x, now.y, (now.turn + 1) % 4) && vis[now.x][now.y][(now.turn + 1) % 4] == 0x7f7f7f7f) {
            vis[now.x][now.y][(now.turn + 1) % 4] = vis[now.x][now.y][now.turn] + 1;
            qu.push((node){now.x, now.y, (now.turn + 1) % 4});
        }
        if (check(now.x, now.y, (now.turn - 1 + 4) % 4) && vis[now.x][now.y][(now.turn - 1 + 4) % 4] == 0x7f7f7f7f) {
            vis[now.x][now.y][(now.turn - 1 + 4) % 4] = vis[now.x][now.y][now.turn] + 1;
            qu.push((node){now.x, now.y, (now.turn - 1 + 4) % 4});
        }
    }
    int mi = 0x7f7f7f7f;
    for (int i = 0; i < 4; i++)
        mi = std::min(mi, vis[end.x][end.y][i]);
    printf("%d", mi == 0x7f7f7f7f ? -1 : mi);
    return 0;
}