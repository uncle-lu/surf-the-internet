#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2e3 + 10, M = 6e3 + 10;
struct node {
    int v, next, val;
};
node edge[M];
int head[N], tot[N], d[N], cnt, n, m;
bool vis[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    edge[cnt].val = val;
    head[x] = cnt;
    return;
}

bool spfa(int start) {
    queue<int> qu;
    qu.push(start);
    vis[start] = true;
    d[start] = 0;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        vis[now] = false;
        if (tot[now] >= n) {
            return true;
        }
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (d[v] > d[now] + edge[i].val) {
                d[v] = d[now] + edge[i].val;
                if (vis[v])
                    continue;
                vis[v] = true;
                tot[v]++;
                qu.push(v);
            }
        }
    }
    return false;
}

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(tot, 0, sizeof(tot));
    memset(vis, false, sizeof(vis));
    memset(d, 0x7f, sizeof(d));
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (w < 0)
                add_edge(u, v, w);
            else {
                add_edge(u, v, w);
                add_edge(v, u, w);
            }
        }
        printf("%s\n", (spfa(1) ? "YES" : "NO"));
    }
    return 0;
}