#include <algorithm>
#include <cstdio>

const int N = 6e4 + 10;
struct node {
    int l, r;
    int min, lazy;
};
node tree[N * 4];
int c, s, R;

void push_up(int x) {
    tree[x].min = std::min(tree[x * 2].min, tree[x * 2 + 1].min);
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].min = s;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    push_up(x);
    return;
}

void make_tag(int x, int p) {
    tree[x].min -= p;
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
    int mid = (tree[x].l + tree[x].r) / 2;
    push_down(x);
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
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    push_down(x);
    if (cl <= mid)
        update_tree(x * 2, cl, cr, p);
    if (cr > mid)
        update_tree(x * 2 + 1, cl, cr, p);
    push_up(x);
    return;
}

int main() {
    int l, r, v;
    scanf("%d %d %d", &c, &s, &R);
    build_tree(1, 1, c);
    for (int i = 1; i <= R; i++) {
        scanf("%d %d %d", &l, &r, &v);
        if (r < l)
            std::swap(l, r);
        if (query_min(1, l, r - 1) >= v) {
            printf("T\n");
            update_tree(1, l, r - 1, v);
        } else
            printf("N\n");
    }
    return 0;
}