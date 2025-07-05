#include <cstdio>
#include <cstring>
#include <set>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[N * 2];
int head[N], wc[N], size[N], top[N], fa[N], depth[N], dfn[N], redfn[N], tot, cnt, n, q;
struct compare {
    bool operator()(int a, int b) const {
        return depth[a] < depth[b];
    }
};
std::set<int, compare> s[N];
bool color[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS_1(int x, int f) {
    dfn[x] = ++tot;
    redfn[tot] = x;
    fa[x] = f;
    depth[x] = depth[f] + 1;
    size[x] = 1;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == f)
            continue;
        DFS_1(v, x);
        size[x] += size[v];
        if (size[wc[x]] < size[v])
            wc[x] = v;
    }
    return;
}

void DFS_2(int x, int Top) {
    top[x] = Top;
    if (wc[x])
        DFS_2(wc[x], Top);
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa[x] || v == wc[x])
            continue;
        DFS_2(v, v);
    }
    return;
}

int query(int x) {
    int ans = -1;
    while (top[x] != 1) {
        if (s[top[x]].size() > 0) {
            int fir = *s[top[x]].begin();
            if (depth[fir] <= depth[x])
                ans = fir;
        }
        x = fa[top[x]];
    }
    if (s[top[x]].size() > 0) {
        int fir = *s[top[x]].begin();
        if (depth[fir] <= depth[x])
            ans = fir;
    }
    return ans;
}

int main() {
    memset(head, -1, sizeof(head));
    int u, v, model;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    DFS_1(1, 0);
    DFS_2(1, 1);
    while (q--) {
        scanf("%d %d", &model, &u);
        if (!model) {
            if (color[u])
                s[top[u]].erase(u);
            else
                s[top[u]].insert(u);
            color[u] = !color[u];
        } else {
            printf("%d\n", query(u));
        }
    }
    return 0;
}