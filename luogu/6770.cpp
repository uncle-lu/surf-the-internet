#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 510, M = 1010;
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
int head[N], dis[N], cnt;
bool vis[N];
int f, p, c, m;

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
    scanf("%d %d %d %d", &f, &p, &c, &m);
    for (int i = 1; i <= p; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
        add_edge(v, u, val);
    }
    dijkstra();
    vector<int> ans;
    for (int i = 1; i <= c; i++) {
        int x;
        scanf("%d", &x);
        if (dis[x] <= m)
            ans.push_back(i);
    }
    printf("%zu\n", ans.size());
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        printf("%d\n", i);
    return 0;
}