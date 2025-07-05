#include <cstdio>
#include <utility>
using namespace std;

const int N = 50010;
struct node {
    int l, r;
    int val; bool flag;
};
pair<int, int> line[N];
node tree[N * 4];
int n, cnt;

int search(int x) { // 查找x年所在数组的位置
    int l = 1, r = cnt;
    while (l < r) {
        int mid = (l + r) / 2;
        if (line[mid].first >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].val = line[l].second;
        tree[x].flag = line[l].second == -1 ? true : false;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x * 2, l, mid);
    build_tree(x * 2 + 1, mid + 1, r);
    if (tree[x * 2].val == -1 || tree[x * 2 + 1].val == -1)
        tree[x].val = -1;
    else
        tree[x].val = (tree[x * 2].val > tree[x * 2 + 1].val ? tree[x * 2].val : tree[x * 2 + 1].val);
    return ;
}

int query_tree(int x, int sl, int sr) {
    if(tree[x].l >= sl && tree[x].r <= sr)
        return tree[x].val;
    int mid = (tree[x].l + tree[x].r) / 2, ans = 0;
    if(sr <= mid)
        return query_tree(x * 2, sl, sr);
    else if(sl > mid)
        return query_tree(x * 2 + 1, sl, sr);
    else {
        int ltree = query_tree(x * 2, sl, sr);
        int rtree = query_tree(x * 2 + 1, sl, sr);
            return ltree > rtree ? ltree : rtree;
    }
}

bool have_flag_tree(int x, int sl, int sr) {
    if(tree[x].l >= sl && tree[x].r <= sr) 
        return tree[x].flag;
    int mid = (tree[x].l + tree[x].r) / 2;
    if(sr <= mid)
        return have_flag_tree(x * 2, sl, sr);
    else if(sl > mid)
        return have_flag_tree(x * 2 + 1, sl, sr);
    else 
        return have_flag_tree(x * 2, sl, sr) | have_flag_tree(x * 2 + 1, sl, sr);
}

bool check(int l, int x) {
    return line[l].first == x && line[l].second == -1;
}

int main() {
    freopen("in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int y, v;
        scanf("%d %d", &y, &v);
        if (line[cnt].first != y - 1)
            line[++cnt] = make_pair(y - 1, -1);
        line[++cnt] = make_pair(y, v);
    }
    for(int i = 1; i <= cnt; i++)
        printf("y:%d, v:%d\n", line[i].first, line[i].second);
    printf("cnt:%d\n", cnt);
    build_tree(1, 1, cnt);
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y, l, r;
        scanf("%d %d", &x, &y);
        l = search(x);
        r = search(y);
        if(check(l, x) && check(r, y)) {
            if(line[l].second < line[r].second) {
                printf("false\n");
                continue;
            }
            if(line[l].first == line[r].first - 1 && line[l].second == line[r].second) {
                printf("true\n");
                continue;
            } else {
                printf("maybe\n");
                continue;
            }
            
        }
        else if(check(l, x) && !check(r, y)) {

        }
        else if(!check(l, x) && check(r, y)) {

        }
        else {

        }
    }
    return 0;
}