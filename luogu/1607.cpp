#include <algorithm>
#include <cstdio>

const int N = 5e4 + 10;
struct cow {
    int l, r, c, lazy;
    friend bool operator<(const cow a, const cow b) {
        return a.r < b.r || (a.r == b.r && a.l > b.l);
    }
} cows[N];
struct node {
    int l, r, min, lazy;
} tree[20000 * 4];
int k, n, c;

void push_up(int x) {
    tree[x].min = std::min(tree[x * 2].min, tree[x * 2 + 1].min);
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].min = c;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    push_up(x);
    return;
}

void make_tag(int x, int p) {
    tree[x].min += p;
    tree[x].lazy += p;
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

int query_min(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].min;
    push_down(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (cr <= mid)
        return query_min(x * 2, cl, cr);
    else if (cl > mid)
        return query_min(x * 2 + 1, cl, cr);
    else
        return std::min(query_min(x * 2, cl, cr), query_min(x * 2 + 1, cl, cr));
}

void update_tree(int x, int cl, int cr, int p) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        make_tag(x, p);
        return ;
    }
    push_down(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if(cl <= mid)
        update_tree(x * 2, cl, cr, p);
    if(cr > mid)
        update_tree(x * 2 + 1, cl, cr, p);
    push_up(x);
    return ;
}

int main() {
    int ans = 0;
    scanf("%d %d %d", &k, &n, &c);
    build_tree(1, 1, n);
    for (int i = 1; i <= k; i++)
        scanf("%d %d %d", &cows[i].l, &cows[i].r, &cows[i].c);
    std::sort(cows + 1, cows + 1 + k);
    for (int i = 1; i <= k; i++) {
        int res = query_min(1, cows[i].l, cows[i].r);
        if(res == 0)
            continue;
        res = std::min(res, cows[i].c);
        update_tree(1, cows[i].l, cows[i].r - 1, -res);
        ans += res;
    }
    printf("%d", ans);
    return 0;
}