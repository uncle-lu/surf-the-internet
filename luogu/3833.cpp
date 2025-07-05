#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[N];
int head[N], cnt;
struct tree_node {
    int l, r;
    long long int sum, lazy_tag;
} tree[N << 2];
int fa[N], dfn[N], redfn[N], son[N], top[N], wc[N], depth[N], n, tot;

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS_1(int x) {
    son[x]++;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        DFS_1(v);
        son[x] += son[v];
        if (son[v] > son[wc[x]] || wc[x] == 0)
            wc[x] = v;
    }
    return;
}

void DFS_2(int x, int Top) {
    dfn[x] = ++tot;
    redfn[tot] = x;
    top[x] = Top;
    depth[x] = depth[fa[x]] + 1;
    if (wc[x])
        DFS_2(wc[x], Top);
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == wc[x])
            continue;
        DFS_2(v, v);
    }
    return;
}

void push_up(int x) {
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    return;
}

void make_tag(int x, int p) {
    tree[x].lazy_tag += p;
    tree[x].sum += (tree[x].r - tree[x].l + 1) * p;
    return;
}

void push_down(int x) {
    if (!tree[x].lazy_tag)
        return;
    make_tag(x * 2, tree[x].lazy_tag);
    make_tag(x * 2 + 1, tree[x].lazy_tag);
    tree[x].lazy_tag = 0;
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (tree[x].l == tree[x].r)
        return;
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    push_up(x);
    return;
}

void update_tree(int x, int cl, int cr, int p) {
    if (cl <= tree[x].l && cr >= tree[x].r) {
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

long long int query_tree(int x, int cl, int cr) {
    if (cl <= tree[x].l && cr >= tree[x].r)
        return tree[x].sum;
    push_down(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (cr <= mid)
        return query_tree(x * 2, cl, cr);
    else if (cl > mid)
        return query_tree(x * 2 + 1, cl, cr);
    else
        return query_tree(x * 2, cl, cr) + query_tree(x * 2 + 1, cl, cr);
}

void update(int u, int v, int p) {
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]])
            swap(u, v);
        update_tree(1, dfn[top[u]], dfn[u], p);
        u = fa[top[u]];
    }
    update_tree(1, min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), p);
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    int u, v, q, t;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        fa[v] = u;
        add_edge(u, v);
    }
    DFS_1(0);
    DFS_2(0, 0);
    build_tree(1, 1, n);
    scanf("%d", &q);
    char model;
    while (q--) {
        scanf("\n%c", &model);
        if (model == 'A') {
            scanf("%d %d %d", &u, &v, &t);
            update(u, v, t);
        } else if (model == 'Q') {
            scanf("%d", &u);
            printf("%lld\n", query_tree(1, dfn[u], dfn[u] + son[u] - 1));
        }
    }
    return 0;
}