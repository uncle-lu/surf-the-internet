#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 110, M = 1e4 + 10;
struct node {
    int v, next, val;
};
struct heapnode {
    int v, w;
    friend bool operator<(const heapnode a, const heapnode b) {
        return a.w > b.w;
    }
};
node edge[M];
int head[N], dis[N], front[N], frontedge[N], cnt, n, m;
bool vis[N], flag;

void add_edge(int x, int y, int val) {
    edge[cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
    return;
}

void dijkstra(int start) {
    std::priority_queue<heapnode> qu;
    memset(vis, false, sizeof(vis));
    memset(dis, 0x7f, sizeof(dis));
    dis[start] = 0;
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
                if (!flag) {
                    front[v] = x;
                    frontedge[v] = i;
                }
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
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
        add_edge(v, u, val);
    }
    dijkstra(1);
    int before = dis[n], sit = n, ans = 0;
    flag = true;
    while (sit != 1) {
        int c = frontedge[sit];
        edge[c].val *= 2;
        edge[c ^ 1].val *= 2;
        dijkstra(1);
        ans = std::max(ans, std::abs(before - dis[n]));
        edge[c].val /= 2;
        edge[c ^ 1].val /= 2;
        sit = front[sit];
    }
    printf("%d", ans);
    return 0;
}