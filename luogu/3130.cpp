#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;

struct node {
    int l, r, lazy, min;
    long long int sum;
};
node tree[N * 4];
int n, q, line[N];

void pushup(int x) {
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    tree[x].min = min(tree[x * 2].min, tree[x * 2 + 1].min);
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].sum = line[l];
        tree[x].min = line[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    pushup(x);
    return;
}

void maketag(int x, int p) {
    tree[x].lazy += p;
    tree[x].sum += 1ll * (tree[x].r - tree[x].l + 1) * p;
    tree[x].min += p;
    return;
}

void pushdown(int x) {
    if (!tree[x].lazy)
        return;
    maketag(x * 2, tree[x].lazy);
    maketag(x * 2 + 1, tree[x].lazy);
    tree[x].lazy = 0;
    return;
}

void update_tree(int x, int cl, int cr, int p) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        maketag(x, p);
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    pushdown(x);
    if (cl <= mid)
        update_tree(x * 2, cl, cr, p);
    if (cr > mid)
        update_tree(x * 2 + 1, cl, cr, p);
    pushup(x);
    return;
}

int query_min(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].min;
    int mid = (tree[x].l + tree[x].r) / 2;
    pushdown(x);
    if (cr <= mid)
        return query_min(x * 2, cl, cr);
    else if (cl > mid)
        return query_min(x * 2 + 1, cl, cr);
    else
        return min(query_min(x * 2, cl, cr), query_min(x * 2 + 1, cl, cr));
}

long long int query_sum(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].sum;
    int mid = (tree[x].l + tree[x].r) / 2;
    long long int sum = 0;
    pushdown(x);
    if (cl <= mid)
        sum += query_sum(x * 2, cl, cr);
    if (cr > mid)
        sum += query_sum(x * 2 + 1, cl, cr);
    return sum;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    char modle;
    int a, b, c;
    while (q--) {
        scanf("\n%c", &modle);
        if (modle == 'M') {
            scanf("%d %d", &a, &b);
            printf("%d\n", query_min(1, a, b));
        } else if (modle == 'S') {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query_sum(1, a, b));
        } else if (modle == 'P') {
            scanf("%d %d %d", &a, &b, &c);
            update_tree(1, a, b, c);
        }
    }
    return 0;
}