#include <cstdio>

const int N = 1e5 + 10;
struct node {
    int l, r;
    int sum, lazy;
};
node tree[N * 4];
int n, m;

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    return;
}

void maketag(int x) {
    tree[x].lazy = !tree[x].lazy;
    tree[x].sum = (tree[x].r - tree[x].l + 1) - tree[x].sum;
    return;
}

void pushdown(int x) {
    if (!tree[x].lazy)
        return;
    maketag(x * 2);
    maketag(x * 2 + 1);
    tree[x].lazy = !tree[x].lazy;
    return;
}

void update(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        maketag(x);
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    pushdown(x);
    if (cl <= mid)
        update(x * 2, cl, cr);
    if (cr > mid)
        update(x * 2 + 1, cl, cr);
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    return;
}

int query(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].sum;
    int mid = (tree[x].l + tree[x].r) / 2, sum = 0;
    pushdown(x);
    if (cl <= mid)
        sum += query(x * 2, cl, cr);
    if (cr > mid)
        sum += query(x * 2 + 1, cl, cr);
    return sum;
}

int main() {
    scanf("%d %d", &n, &m);
    build_tree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int model, s, e;
        scanf("%d %d %d", &model, &s, &e);
        if (model == 0)
            update(1, s, e);
        else
            printf("%d\n", query(1, s, e));
    }
    return 0;
}