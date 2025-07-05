#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 1e3 + 10;
struct point {
    int x, y;
} line[N];
struct node {
    int u, v;
    double val;
    friend bool operator<(const node a, const node b) {
        return a.val < b.val;
    }
} edge[N * N];
int n, m, cnt, father[N];

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &line[i].x, &line[i].y);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            edge[++cnt] = (node){i, j,
                                 sqrt(1LL * (line[i].x - line[j].x) * (line[i].x - line[j].x) +
                                      1LL * (line[i].y - line[j].y) * (line[i].y - line[j].y))};
    std::sort(edge + 1, edge + 1 + cnt);
    int tot = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u = find_father(u);
        v = find_father(v);
        if (u != v) {
            tot++;
            father[v] = u;
        }
    }
    double sum = 0;
    for (int i = 1; i <= cnt; i++) {
        int x = find_father(edge[i].u), y = find_father(edge[i].v);
        if (x != y) {
            tot++;
            sum += edge[i].val;
            father[y] = x;
        }
        if (tot == n - 1)
            break;
    }
    printf("%.2lf", sum);
    return 0;
}