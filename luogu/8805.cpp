#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[2 * N];
int d[N], head[N], depth[N], f[N][30], s[N], cnt, n, m;

void add_edge(int x, int y) {
    d[x]++;
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x, int fa) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa)
            continue;
        depth[v] = depth[x] + 1;
        s[v] = s[x] + d[v];
        f[v][0] = x;
        DFS(v, x);
    }
    return;
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = 25; i >= 0; i--)
        if (depth[f[x][i]] >= depth[y])
            x = f[x][i];
    if (x == y)
        return x;
    for (int i = 25; i >= 0; i--)
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    return f[x][0];
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    DFS(1, 0);
    f[1][0] = 1;
    for (int j = 1; j <= 25; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int x = lca(u, v);
        printf("%d\n", s[u] + s[v] - 2 * s[x] + d[x]);
    }
    return 0;
}