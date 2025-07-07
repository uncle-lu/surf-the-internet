#include <cstdio>

const int N = 1e5 + 10;
struct node {
    int l, r;
    long long int lazy_add, lazy_mul, sum;
};
node tree[N * 4];
int n, q, m, line[N];

void pushup(int x) {
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy_mul = 1;
    if (l == r) {
        tree[x].sum = line[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    pushup(x);
    return;
}

void maketag(int x, long long int mul, long long int add) {
    tree[x].sum = ((tree[x].sum * mul) + add * (tree[x].r - tree[x].l + 1)) % m;
    tree[x].lazy_mul = tree[x].lazy_mul * mul % m;
    tree[x].lazy_add = (tree[x].lazy_add * mul + add) % m;
    return;
}

void pushdown(int x) {
    if (!tree[x].lazy_add && tree[x].lazy_mul == 1)
        return;
    maketag(x * 2, tree[x].lazy_mul, tree[x].lazy_add);
    maketag(x * 2 + 1, tree[x].lazy_mul, tree[x].lazy_add);
    tree[x].lazy_mul = 1;
    tree[x].lazy_add = 0;
    return;
}

void update(int x, int cl, int cr, long long int mul, int add) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        maketag(x, mul, add);
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    pushdown(x);
    if (cl <= mid)
        update(x * 2, cl, cr, mul, add);
    if (cr > mid)
        update(x * 2 + 1, cl, cr, mul, add);
    pushup(x);
    return;
}

long long int query_sum(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].sum % m;
    int mid = (tree[x].l + tree[x].r) / 2;
    long long int sum = 0;
    pushdown(x);
    if (cl <= mid)
        sum = (sum + query_sum(x * 2, cl, cr)) % m;
    if (cr > mid)
        sum = (sum + query_sum(x * 2 + 1, cl, cr)) % m;
    return sum;
}

int main() {
    freopen("in","r",stdin);
    scanf("%d %d %d", &n, &q, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int model, a, b, c;
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d %d", &a, &b, &c);
            update(1, a, b, c, 0);
        } else if (model == 2) {
            scanf("%d %d %d", &a, &b, &c);
            update(1, a, b, 1, c);
        } else if (model == 3) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query_sum(1, a, b));
        }
    }
    return 0;
}