#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

const int N = 2e5 + 10;
struct node {
    int v, next, val;
} edge[N * 2];
int head[N], pre[N], cnt, n, bfs_end;
long long int d[N], d1[N], d2[N], ds[N], dt[N], ans;
bool vis[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].next = head[x];
    edge[cnt].v = y;
    edge[cnt].val = val;
    head[x] = cnt;
    return;
}

void bfs(int x) {
    memset(d, 0, sizeof(d));
    memset(vis, false, sizeof(vis));
    std::queue<int> qu;
    qu.push(x);
    vis[x] = true;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        if (d[now] > d[bfs_end])
            bfs_end = now;
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (d[v] < d[now] + edge[i].val && !vis[v]) {
                pre[v] = now;
                vis[v] = true;
                d[v] = d[now] + edge[i].val;
                qu.push(v);
            }
        }
    }
    ans = d[bfs_end];
    return;
}

void dfs(long long int *d, int x, int dep) {
    for(int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(vis[v])continue;
        vis[v] = true;
        dfs(d, v, dep);
        if(d1[x] < d1[v] + edge[i].val) {
            d2[x] = d1[x];
            d1[x] = d1[v] + edge[i].val;
        }
        else if(d2[x] < d1[v] + edge[i].val)
            d2[x] = d1[v] + edge[i].val;
        d[x] = std::max(d[x], d[v]);
    }
    d[x] = std::max(d[x], d1[x] + d2[x]);
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
        add_edge(v, u, val);
    }
    int s, t;
    bfs(1);
    s = bfs_end;
    bfs(s);
    t = bfs_end;
    memset(vis, false, sizeof(vis));
    dfs(ds, s, 0);
    memset(vis, false, sizeof(vis));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    dfs(dt, t, 0);
    int edge_cnt = 0;
    for (int i = t; i != s; i = pre[i])
        if (ds[i] < ans && dt[pre[i]] < ans)
            edge_cnt++;
    printf("%lld\n%d", ans, edge_cnt);
    return 0;
}