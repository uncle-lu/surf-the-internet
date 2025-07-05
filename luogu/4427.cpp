#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
struct node {
    int v, next;
} edge[2 * N];
int head[N], cnt;
long long int depth[N], f[N][30], sum[N][53];
long long int n, m;
void add(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
}
int fast(long long int x, int y) {
    long long int ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans % mod;
}
void dfs(int x, int fa) {
    for (int i = 1; i <= 50; i++) {
        sum[x][i] = (sum[fa][i] + fast(depth[x], i) + mod) % mod;
    }
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa)
            continue;
        f[v][0] = x;
        depth[v] = depth[x] + 1;
        dfs(v, x);
    }
}
int lca(int x, int y) {
    if (depth[x] > depth[y])
        swap(x, y);
    for (int i = 25; i >= 0; i--) {
        if (depth[f[x][i]] >= depth[y]) {
            x = f[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 25; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 1);
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i - 1]][i - 1];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        int k = lca(x, y);
        cout << (long long)(sum[x][z] + sum[y][z] + 2 * mod - (sum[k][z] + sum[f[k][0]][z])) % mod << endl;
    }
    return 0;
}