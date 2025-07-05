#include <algorithm>
#include <cstdio>

const int N = 5e5 + 10;
struct node {
    int l, r, lsum, rsum, sum, val;
} tree[N * 4];
int n, m, line[N];

void push_up(int x) {
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    tree[x].lsum = std::max(tree[x * 2].lsum, tree[x * 2].sum + tree[x * 2 + 1].lsum);
    tree[x].rsum = std::max(tree[x * 2 + 1].rsum, tree[x * 2 + 1].sum + tree[x * 2].rsum);
    tree[x].val = std::max({tree[x * 2].val, tree[x * 2 + 1].val, tree[x * 2].rsum + tree[x * 2 + 1].lsum});
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].lsum = tree[x].rsum = tree[x].sum = tree[x].val = line[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    push_up(x);
    return;
}

node query_val(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x];
    int mid = (tree[x].l + tree[x].r) / 2;
    if (cr <= mid)
        return query_val(x * 2, cl, cr);
    else if (cl > mid)
        return query_val(x * 2 + 1, cl, cr);
    else {
        node lt = query_val(x * 2, cl, cr), rt = query_val(x * 2 + 1, cl, cr), t;
        t.sum = lt.sum + rt.sum;
        t.lsum = std::max(lt.lsum, lt.sum + rt.lsum);
        t.rsum = std::max(rt.rsum, rt.sum + lt.rsum);
        t.val = std::max({lt.val, rt.val, lt.rsum + rt.lsum});
        return t;
    }
}

void update_tree(int x, int p, int val) {
    if (tree[x].l == tree[x].r) {
        tree[x].lsum = tree[x].rsum = tree[x].sum = tree[x].val = val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (p <= mid)
        update_tree(x * 2, p, val);
    else
        update_tree(x * 2 + 1, p, val);
    push_up(x);
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int model, x, y;
        scanf("%d %d %d", &model, &x, &y);
        if (model == 1) {
            if (x > y)
                std::swap(x, y);
            printf("%d\n", query_val(1, x, y).val);
        } else {
            update_tree(1, x, y);
        }
    }
    return 0;
}