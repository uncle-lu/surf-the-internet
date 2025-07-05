#include <cmath>
#include <cstdio>

const int N = 510;
int d[N][N], line[N * N], father[N * N], cnt, n, m;
int x_turn[4] = {0, 0, 1, -1};
int y_turn[4] = {1, -1, 0, 0};

int turn(int x, int y) {
    return (x - 1) * m + y;
}

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

bool check(int x) {
    for (int i = 1; i <= n * m; i++)
        father[i] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int t = 0; t < 4; t++) {
                int xx = i + x_turn[t], yy = j + y_turn[t];
                if (xx < 1 || xx > n || yy < 1 || yy > m || std::abs(d[i][j] - d[xx][yy]) > x)
                    continue;
                father[find_father(turn(xx, yy))] = find_father(turn(i, j));
            }

    for (int i = 2; i <= cnt; i++)
        if (find_father(line[i]) != find_father(line[i - 1]))
            return false;

    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &d[i][j]);
    int temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &temp);
            if (temp)
                line[++cnt] = turn(i, j);
        }
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d", l);
    return 0;
}