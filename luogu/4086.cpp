#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e6 + 10;
struct node {
    int l, r;
    int mi, sum;
};
node tree[N];
int n, line[N], ans[N], cnt;

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].sum = tree[x].mi = line[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
    tree[x].mi = min(tree[x * 2].mi, tree[x * 2 + 1].mi);
    return;
}

int query_sum_tree(int x, int l, int r) {
    if (tree[x].l >= l && tree[x].r <= r)
        return tree[x].sum;
    int mid = (tree[x].l + tree[x].r) / 2, sum = 0;
    if (l <= mid)
        sum += query_sum_tree(x * 2, l, r);
    if (r > mid)
        sum += query_sum_tree(x * 2 + 2, l, r);
    return sum;
}

int query_min_tree(int x, int l, int r) {
    if (tree[x].l >= l && tree[x].r <= r)
        return tree[x].mi;
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid)
        return query_min_tree(x * 2, l, r);
    else if (l > mid)
        return query_min_tree(x * 2 + 1, l, r);
    else
        return min(query_min_tree(x * 2, l, r), query_min_tree(x * 2 + 1, l, r));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    double sc, last;
    for (int k = 1; k <= n - 2; k++) {
        int s = query_sum_tree(1, k + 1, n);
        int mi = query_min_tree(1, k + 1, n);
        sc = (double)(s - mi) / (n - k - 1);
        if (sc > last) {
            cnt = 1;
            ans[cnt] = k;
        } else if (sc == last) {
            ans[++cnt] = k;
        }
    }
    for (int i = 1; i <= cnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}