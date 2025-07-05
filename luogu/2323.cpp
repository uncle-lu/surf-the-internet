#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
bool vis[2][N];
int a[N], q[N];
int n, k, m, mx = -1, tot;
struct node {
    int u, v, val, id;
    friend bool operator<(const node a, const node b) {
        return a.val < b.val;
    }
} edge[N];
int f(int x) {
    if (q[x] == x) {
        return x;
    }
    return q[x] = f(q[x]);
}
void kr(int check) {
    for (int i = 1; i < m; i++) {
        if (check == 0 && tot == k) {
            break;
        }
        if (check == 1 && tot == n - 1) {
            break;
        }
        int x = f(edge[i].u), y = f(edge[i].v);
        if (x != y) {
            tot++;
            q[x] = y;
            mx = max(mx, edge[i].val);
            vis[check][edge[i].id] = true;
        }
    }
}
int main() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        q[i] = i;
    }
    for (int i = 1; i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].val >> a[i];
        edge[i].id = i;
    }
    sort(edge + 1, edge + m);
    kr(0);
    for (int i = 1; i < m; i++) {
        edge[i].val = a[edge[i].id];
    }
    sort(edge + 1, edge + m);
    kr(1);
    cout << mx << endl;
    for (int i = 1; i < m; i++) {
        if (vis[0][i]) {
            cout << i << " " << 1 << endl;
        } else if (vis[1][i]) {
            cout << i << " " << 2 << endl;
        }
    }
    return 0;
}