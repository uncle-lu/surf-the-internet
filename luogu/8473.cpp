#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int INF = 0x7f7f7f7f;
struct node {
    int l, r, min, lazy;
};
node tree[N * 4];
int n, q, L[N], R[N];
int line[N], color[N], line_black[N], sit_black[N], cnt_black;

void push_up(int x) {
    tree[x].min = min(tree[x * 2].min, tree[x * 2 + 1].min);
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].min = color[l];
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
        return min(query_min(x * 2, cl, cr), query_min(x * 2 + 1, cl, cr));
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

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        if (color[i] == 1) {
            line_black[++cnt_black] = line[i];
            sit_black[cnt_black] = i;
            color[i] = INF;
        }
    }
    cnt_black++;
    line_black[cnt_black] = INF;
    build_tree(1, 1, n);
    printf(query_min(1, 1, n) == 0 ? "NO\n" : "YES\n");
    for (int i = 1; i <= q; i++) {
        int model, x;
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d", &L[i], &R[i]);
            L[i] = sit_black[lower_bound(line_black + 1, line_black + cnt_black + 1, L[i]) - line_black];
            R[i] = sit_black[upper_bound(line_black + 1, line_black + cnt_black + 1, R[i]) - line_black - 1];
            update_tree(1, L[i], R[i], 1);
        } else {
            scanf("%d", &x);
            update_tree(1, L[x], R[x], -1);
        }
        printf(query_min(1, 1, n) == 0 ? "NO\n" : "YES\n");
    }
    return 0;
}