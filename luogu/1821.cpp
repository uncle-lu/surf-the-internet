#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e3 + 10, M = 1e5 + 10;
struct qu_node {
    int v, w;
    friend bool operator<(const qu_node a, qu_node b) {
        return a.w > b.w;
    }
};
struct node {
    int v, next, val;
};
node edge[M], redge[M];
int head[N], rhead[N], dis[N], rdis[N], cnt, rcnt, n, m, start;
bool vis[N];

void add_edge(int x, int y, int val, node *e, int *h, int &c) {
    e[++c].v = y;
    e[c].val = val;
    e[c].next = h[x];
    h[x] = c;
    return;
}

void dijkstra(node *e, int *h, int *d) {
    memset(vis, false, sizeof(vis));
    priority_queue<qu_node> qu;
    d[start] = 0;
    qu.push((qu_node){start, 0});
    while (!qu.empty()) {
        qu_node now = qu.top();
        qu.pop();
        int x = now.v;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = h[x]; ~i; i = e[i].next) {
            int v = e[i].v;
            if (d[v] > d[x] + e[i].val) {
                d[v] = d[x] + e[i].val;
                qu.push((qu_node){v, d[v]});
            }
        }
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    memset(dis, 0x7f, sizeof(dis));
    memset(rdis, 0x7f, sizeof(rdis));
    scanf("%d %d %d", &n, &m, &start);
    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val, edge, head, cnt);
        add_edge(v, u, val, redge, rhead, rcnt);
    }
    dijkstra(edge, head, dis);
    dijkstra(redge, rhead, rdis);
    int mx = dis[1] + rdis[1];
    for (int i = 1; i <= n; i++)
        mx = max(mx, dis[i] + rdis[i]);
    printf("%d", mx);
    return 0;
}