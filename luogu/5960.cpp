#include <cstdio>
#include <cstring>
#include <queue>

const int N = 5e3 + 10;
struct node {
    int v, next, val;
};
node edge[N * 3];
int head[N], d[N], tot[N], cnt, n, m;
bool vis[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

bool spfa(int start) {
    std::queue<int> qu;
    qu.push(start);
    d[start] = 0;
    vis[start] = true;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        if (tot[now] > n) {
            return false;
        }
        vis[now] = false;
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (d[v] > d[now] + edge[i].val) {
                d[v] = d[now] + edge[i].val;
                if (!vis[v]) {
                    vis[v] = true;
                    qu.push(v);
                    tot[v]++;
                }
            }
        }
    }
    return true;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(d, 0x7f, sizeof(d));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(v, u, val);
    }
    for (int i = 1; i <= n; i++)
        add_edge(0, i, 0);
    if (spfa(0)) {
        for (int i = 1; i <= n; i++)
            printf("%d ", d[i]);
    } else
        printf("NO");
    return 0;
}