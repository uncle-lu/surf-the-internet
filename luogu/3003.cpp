#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
struct node {
    int v, next, val;
};
struct heapnode {
    int v, w;
    friend bool operator<(const heapnode a, const heapnode b) {
        return a.w > b.w;
    }
};
node edge[2 * M];
int head[N], dis[N], cnt, n, m, pb, p1, p2;
bool vis[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dijkstra(int start) {
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[start] = 0;
    priority_queue<heapnode> qu;
    qu.push((heapnode){start, 0});
    while (!qu.empty()) {
        heapnode now = qu.top();
        qu.pop();
        int x = now.v;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > dis[x] + edge[i].val) {
                dis[v] = dis[x] + edge[i].val;
                qu.push((heapnode){v, dis[v]});
            }
        }
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d %d %d %d", &m, &n, &pb, &p1, &p2);
    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
        add_edge(v, u, val);
    }
    dijkstra(pb);
    int ans = min(dis[p1], dis[p2]);
    dijkstra(p1);
    ans += dis[p2];
    printf("%d", ans);
    return 0;
}