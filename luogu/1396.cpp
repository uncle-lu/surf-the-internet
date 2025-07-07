#include <algorithm>
#include <cstdio>
using namespace std;

const int M = 2e5 + 10, N = 1e4 + 10;
struct node {
    int u, v, val;
    friend bool operator<(const node a, const node b) {
        return a.val < b.val;
    }
} edge[M];
int father[N], n, m;

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
    int s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].val);
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++) {
        int fu = find_father(edge[i].u), fv = find_father(edge[i].v);
        if (fu != fv) {
            father[fv] = fu;
            if (find_father(s) == find_father(t)) {
                printf("%d", edge[i].val);
                break;
            }
        }
    }
    return 0;
}