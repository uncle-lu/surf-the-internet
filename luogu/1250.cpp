#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int H = 5e3 + 10, N = 3e4 + 10;
struct node {
    int v, next, val;
};
node edge[H + 2 * N];
int head[N], d[N], cnt, n, h;
bool vis[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void spfa(int start) {
    queue<int> qu;
    qu.push(start);
    vis[start] = true;
    d[start] = 0;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        vis[now] = false;
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (d[v] < d[now] + edge[i].val) {
                d[v] = d[now] + edge[i].val;
                if (!vis[v]) {
                    vis[v] = true;
                    qu.push(v);
                }
            }
        }
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &h);
    for (int i = 1; i <= h; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u - 1, v, val);
    }
    for (int i = 1; i <= n; i++) {
        add_edge(i - 1, i, 0);
        add_edge(i, i - 1, -1);
        d[i] = -1e9;
    }
    spfa(0);
    printf("%d", d[n]);
    return 0;
}