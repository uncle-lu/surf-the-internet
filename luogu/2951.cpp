#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2e4 + 10, M = 5e4 + 10;
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
int head[N], dis[N], cnt, n, m;
bool vis[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dijkstra() {
    memset(dis, 0x7f, sizeof(dis));
    dis[1] = 0;
    priority_queue<heapnode> qu;
    qu.push((heapnode){1, 0});
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
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
    dijkstra();
    int mx = 0, tot = 0, first = 0;
    for (int i = 2; i <= n; i++)
        mx = max(mx, dis[i]);
    for (int i = 2; i <= n; i++)
        if (dis[i] == mx) {
            first = (first == 0 ? i : first);
            tot++;
        }
    printf("%d %d %d", first, mx, tot);
    return 0;
}