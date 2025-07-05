#include <algorithm>
#include <cstring>
#include <iostream>
#define endl '\n'
using namespace std;

const int N = 1e5 + 3, M = 3e5 + 3, INF = 0x3f3f3f3f, LIM = 20;

int n, m, q;
int h[N], e[2 * N], ne[2 * N], weight[2 * N], idx;
int p[N];
int fa[N][LIM];
int g_min[N][LIM];
int depth[N];

struct Edg {
    int u, v, w;
    friend bool operator<(const Edg x, const Edg y) {
        return x.w > y.w;
    }
} edg[M];

int find(int u) {
    return p[u] == u ? u : p[u] = find(p[u]);
}

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], weight[idx] = c, h[a] = idx++;
}

void dfs(int u, int Fa) {
    depth[u] = depth[Fa] + 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], w = weight[i];
        if (v == Fa)
            continue;
        fa[v][0] = u;
        g_min[v][0] = w;
        for (int i = 1; i < LIM; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
            g_min[v][i] = min(g_min[v][i - 1], g_min[fa[v][i - 1]][i - 1]);
            // cout << "#" << g_min[v][i] << endl;
        }
        dfs(v, u);
    }
}

int lca(int a, int b) {
    int min_a, min_b;
    min_a = min_b = INF;
    if (depth[a] < depth[b])
        swap(a, b);
    if (a == b)
        return INF;
    for (int i = LIM - 1; i >= 0; i--) {
        if (depth[fa[a][i]] >= depth[b]) {
            min_a = min(min_a, g_min[a][i]);
            a = fa[a][i];
        }
    }
    if (a == b)
        return min_a;
    for (int i = LIM - 1; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            min_a = min(min_a, g_min[a][i]);
            min_b = min(min_b, g_min[b][i]);
            a = fa[a][i], b = fa[b][i];
        }
    }
    min_a = min(min_a, g_min[a][0]);
    min_b = min(min_b, g_min[b][0]);
    return min(min_a, min_b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> q;
    memset(h, -1, sizeof h);
    memset(g_min, 0x3f, sizeof g_min);
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m && i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[i] = {u, v, w};
    }
    sort(edg, edg + m);
    for (int i = 0; i < m; i++) {
        int u = find(edg[i].u), v = find(edg[i].v), w = edg[i].w;
        if (u != v) {
            p[v] = u;
            add(u, v, w);
            add(v, u, w);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (depth[i] == 0) {
            dfs(i, 0);
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y)) {
            cout << -1 << endl;
        } else {
            int LCA_min = lca(x, y);
            cout << LCA_min << endl;
        }
    }
    return 0;
}