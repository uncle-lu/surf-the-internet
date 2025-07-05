#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 500010;
struct tnode {
    int l, r, sit;
} tree[16 * N];
struct node {
    int v, next;
} edge[30 * N];
int n, cntval, cnt, num, top, scc_cnt;
long long lx[N], r[N], val[3 * N];
int x[N], left[N], right[N], tree_node[3 * N], head[12 * N], dfn[12 * N], low[12 * N], sta[12 * N], scc[12 * N],
    scc_left[12 * N], scc_right[12 * N], tong[4 * N];
std::bitset<12 * N> vis;
std::vector<int> edge2[12 * N];

void add_edge(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
    return;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++num;
    sta[++top] = u;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (vis[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int v;
        scc_cnt++;
        do {
            v = sta[top--];
            vis[v] = 0;
            scc[v] = scc_cnt;
            if (tree[v].sit) {
                scc_left[scc_cnt] = std::min(scc_left[scc_cnt], left[tree[v].sit]);
                scc_right[scc_cnt] = std::max(scc_right[scc_cnt], right[tree[v].sit]);
            }
        } while (v != u);
    }
    return;
}

void build_tree(int u, int cl, int cr) {
    tree[u].l = cl;
    tree[u].r = cr;
    if (cl == cr) {
        tree_node[cl] = u;
        return;
    }
    int mid = (cl + cr) / 2;
    add_edge(u, u * 2);
    build_tree(u * 2, cl, mid);
    add_edge(u, u * 2 + 1);
    build_tree(u * 2 + 1, mid + 1, cr);
    return;
}

void query(int u, int sit, int cl, int cr) {
    if (cl <= tree[u].l && tree[u].r <= cr) {
        if (u != sit)
            add_edge(sit, u);
        return;
    }
    int mid = (tree[u].l + tree[u].r) / 2;
    if (cl <= mid)
        query(u * 2, sit, cl, cr);
    if (cr > mid)
        query(u * 2 + 1, sit, cl, cr);
    return;
}

void dfs(int u) {
    vis[u] = true;
    for (auto v : edge2[u]) {
        if (!vis[v])
            dfs(v);
        scc_left[u] = std::min(scc_left[u], scc_left[v]);
        scc_right[u] = std::max(scc_right[u], scc_right[v]);
    }
    return;
}

int main() {
    freopen("bomb10.in","r",stdin);
    memset(head, -1, sizeof(head));
    memset(scc_left, 0x7f, sizeof(scc_left));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &lx[i], &r[i]);
        val[i * 3 - 2] = lx[i];
        val[i * 3 - 1] = lx[i] - r[i];
        val[i * 3] = lx[i] + r[i];
    }
    std::sort(val + 1, val + 3 * n + 1);
    cntval = std::unique(val + 1, val + 3 * n + 1) - val - 1;
    for (int i = 1; i <= n; i++)
        x[i] = std::lower_bound(val + 1, val + 1 + cntval, lx[i]) - val;
    build_tree(1, 1, cntval);
    for (int i = 1; i <= n; i++) {
        tree[tree_node[x[i]]].sit = i;
        tong[x[i]]++;
    }
    for (int i = 1; i <= cntval; i++)
        tong[i] += tong[i - 1];
    for (int i = 1; i <= n; i++) {
        left[i] = std::lower_bound(val + 1, val + 1 + cntval, val[x[i]] - r[i]) - val;
        right[i] = std::lower_bound(val + 1, val + 1 + cntval, val[x[i]] + r[i]) - val;
        query(1, tree_node[x[i]], left[i], right[i]);
    }
    tarjan(1);
    for (int u = 1; u <= num; u++)
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (scc[u] == scc[v])
                continue;
            edge2[scc[u]].push_back(scc[v]);
        }
    for (int i = 1; i <= scc_cnt; i++) {
        std::sort(edge2[i].begin(), edge2[i].end());
        static_cast<void>(std::unique(edge2[i].begin(), edge2[i].end()));
    }
    vis.set(0);
    for (int i = 1; i <= scc_cnt; i++)
        if (!vis[i]) {
            dfs(i);
        }
    int all = 0;
    for (int i = 1; i <= n; i++) {
        int temp = scc[tree_node[x[i]]];
        all = ((long long)(tong[scc_right[temp]] - tong[scc_left[temp] - 1]) * i + all) % 1000000007;
    }
    printf("%d", all);
    return 0;
}
