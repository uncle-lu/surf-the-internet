#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e6+10;
int n, line[N];
struct node {
    int l, r, val, sit;
};
node tree[N*4];

void build_tree(int x, int l, int r) {
    tree[x].l = l; tree[x].r = r;
    if(l == r) {
        tree[x].val = line[l];
        tree[x].sit = l;
        return ;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    if(tree[x * 2].val > tree[x * 2 + 1].val) {
        tree[x].val = tree[x * 2].val;
        tree[x].sit = tree[x * 2].sit;
    } else {
        tree[x].val = tree[x * 2 + 1].val;
        tree[x].sit = tree[x * 2 + 1].sit;
    }
    return ;
}

int query_tree(int x, int l, int r) {
    if(tree[x].l >= l && tree[x].r <= r) 
        return tree[x].sit;
    int mid = (tree[x].l + tree[x].r) / 2;
    if(r <= mid)
        return query_tree(x * 2, l, r);
    else if(l > mid)
        return query_tree(x * 2 + 1, l, r);
    else {
        int ltree = query_tree(x*2, l, r);
        int rtree = query_tree(x*2+1, l, r);
        if(line[ltree] > line[rtree])
            return ltree;
        else
            return rtree;
    }
}

long long int dfs(int l, int r) {
    if(l > r)
        return 0;
    if(l == r)
        return 0;
    int mx_sit = query_tree(1, l, r);
    long long int ans = 0;
    if(mx_sit > l) 
        ans += dfs(l, mx_sit - 1) + line[mx_sit];
    if(mx_sit < r) 
        ans += dfs(mx_sit + 1, r) + line[mx_sit];
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    printf("%lld", dfs(1, n));
    return 0;
}