#include <bits/stdc++.h>
using namespace std;
int m, n, t, f[100040], head[100040], cnt, line[100050], ccnt;
struct node {
    int u, v, val;

} edge[100040];
struct Edge {
    int v, val, nex;
} edge1[200040];
int findf(int x) {
    return f[x] == x ? x : f[x] = findf(f[x]);
}
void add(int u, int v, int val) {
    edge1[++cnt].v = v;
    edge1[cnt].val = val;
    edge1[cnt].nex = head[u];
    head[u] = cnt;
}
bool dfs(int u, int v, int fa) {
    if (u == v)
        return 1;
    for (int i = head[u]; i != -1; i = edge1[i].nex) {
        if (edge1[i].v == fa) {
            continue;
        }
        line[++ccnt] = edge1[i].val;
        if (dfs(edge1[i].v, v, u) == 1) {
            return 1;
        }
        ccnt--;
    }
    return 0;
}
int main() {
    cin >> t;
    while (t--) {
        bool fl = 0;
        cnt = ccnt = 0;
        memset(head, -1, sizeof(head));
        memset(line, 0, sizeof(line));
        memset(edge, 0, sizeof(edge));
        memset(edge1, 0, sizeof(edge1));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            f[i] = i;
        for (int i = 1; i <= m; i++) {
            cin >> edge[i].u >> edge[i].v;
            edge[i].val = i;
        }
        int tot = 0;
        for (int i = 1; i <= m; i++) {
            int fx = findf(edge[i].u), fy = findf(edge[i].v);
            if (fx != fy) {
                tot++;
                f[fy] = fx;
                add(edge[i].u, edge[i].v, i);
                add(edge[i].v, edge[i].u, i);
            } else {
                if (dfs(edge[i].u, edge[i].v, 0) == 1) {
                    fl = 1;
                    line[++ccnt] = edge[i].val;
                    sort(line + 1, line + 1 + ccnt);
                    for (int j = 1; j <= ccnt; j++) 
                        cout << line[j] << " ";
                    cout << endl;
                    break;
                }
            }
        }
        if (tot <= n - 1 && fl != 1) 
            cout << -1 << endl;
    }
}