#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 * 10;
struct node {
    int l, r;
    long long int val;
} tree[N * 4];

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build_tree(x << 1, l, mid);
    build_tree(x << 1 | 1, mid + 1, r);
    return;
}

void add_tree(int x, int sit, long long int val) {
    if (tree[x].l == tree[x].r) {
        tree[x].val = val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (sit <= mid)
        add_tree(x << 1, sit, val);
    else
        add_tree(x << 1 | 1, sit, val);
    tree[x].val = max(tree[x << 1].val, tree[x << 1 | 1].val);
    return;
}

long long int search_tree(int x, int l, int r) {
    if (tree[x].l >= l && tree[x].r <= r)
        return tree[x].val;
    int mid = (tree[x].l + tree[x].r) >> 1;
    long long int val = 0;
    if (l <= mid)
        val = max(val, search_tree(x << 1, l, r));
    if (r > mid)
        val = max(val, search_tree(x << 1 | 1, l, r));
    return val;
}

int main() {
    int m, len = 0;
    long long int d, temp, ans = 0;
    char model;
    scanf("%d %lld", &m, &d);
    build_tree(1, 1, m);
    for (int i = 1; i <= m; i++) {
        scanf("\n%c %lld", &model, &temp);
        if (model == 'A') {
            len++;
            add_tree(1, len, (ans + temp) % d);
        } else {
            if (temp == 0)
                ans = 0;
            else
                ans = search_tree(1, len - temp + 1, len);
            printf("%lld\n", ans);
        }
    }
    return 0;
}