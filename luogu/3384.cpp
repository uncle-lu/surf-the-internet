#include <cstdio>
#include <vector>

const int N = 1e5 + 10;
struct tnode {
    int l, r;
    long long int sum, lazy;
} tree[N * 4];
int n, m, root, mod, cnt;
int val[N], size[N], wc[N], dfn[N], top[N], depth[N], line[N], father[N];

std::vector<int> edge[N];

void DFS1(int x, int fa) {
    father[x] = fa;
    depth[x] = depth[fa] + 1;
    size[x] = 1;
    for (int i = 0; i < (int)edge[x].size(); i++) {
        int v = edge[x][i];
        if (v == fa)
            continue;
        DFS1(v, x);
        size[x] += size[v];
        if (size[v] > size[wc[x]])
            wc[x] = v;
    }
    return;
}

void DFS2(int x, int fa, int Top) {
    dfn[x] = ++cnt;
    top[x] = Top;
    if (wc[x])
        DFS2(wc[x], x, Top);
    for (int i = 0; i < (int)edge[x].size(); i++) {
        int v = edge[x][i];
        if (v == fa || v == wc[x])
            continue;
        DFS2(v, x, v);
    }
    return;
}

void push_up(int x) {
    tree[x].sum = (tree[x * 2].sum + tree[x * 2 + 1].sum) % mod;
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].sum = line[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    push_up(x);
    return;
}

void make_tag(int x, int p) {
    tree[x].sum = (tree[x].sum + 1ll * (tree[x].r - tree[x].l + 1) * p % mod) % mod;
    tree[x].lazy = (tree[x].lazy + p) % mod;
    return;
}

void push_down(int x) {
    if (!tree[x].lazy)
        return;
    make_tag(x * 2, tree[x].lazy);
    make_tag(x * 2 + 1, tree[x].lazy);
    tree[x].lazy = 0;
    return;
}

long long int query_tree(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].sum;
    push_down(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (cr <= mid)
        return query_tree(x * 2, cl, cr);
    else if (cl > mid)
        return query_tree(x * 2 + 1, cl, cr);
    else
        return (query_tree(x * 2, cl, cr) + query_tree(x * 2 + 1, cl, cr)) % mod;
}

void update_tree(int x, int cl, int cr, int p) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        make_tag(x, p);
        return;
    }
    push_down(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (cl <= mid)
        update_tree(x * 2, cl, cr, p);
    if (cr > mid)
        update_tree(x * 2 + 1, cl, cr, p);
    push_up(x);
    return;
}

void update(int x, int y, int p) {
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
        update_tree(1, dfn[top[x]], dfn[x], p);
        x = father[top[x]];
    }
    update_tree(1, std::min(dfn[x], dfn[y]), std::max(dfn[x], dfn[y]), p);
    return;
}

long long int query(int x, int y) {
    long long int sum = 0;
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
        sum = (sum + query_tree(1, dfn[top[x]], dfn[x])) % mod;
        x = father[top[x]];
    }
    sum = (sum + query_tree(1, std::min(dfn[x], dfn[y]), std::max(dfn[x], dfn[y]))) % mod;
    return sum;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &root, &mod);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    DFS1(root, 0);
    DFS2(root, 0, root);
    for (int i = 1; i <= n; i++)
        line[dfn[i]] = val[i];
    build_tree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int model, x, y, z;
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d %d", &x, &y, &z);
            update(x, y, z);
        } else if (model == 2) {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(x, y) % mod);
        } else if (model == 3) {
            scanf("%d %d", &x, &z);
            update_tree(1, dfn[x], dfn[x] + size[x] - 1, z);
        } else {
            scanf("%d", &x);
            printf("%lld\n", query_tree(1, dfn[x], dfn[x] + size[x] - 1) % mod);
        }
    }
    return 0;
}