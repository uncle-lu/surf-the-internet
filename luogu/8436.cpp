#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int M = 4e6 + 10, N = 5e5 + 10;
struct node {
    int v, next;
} edge[M];
int n, m, cnt, num, head[N], dfn[N], low[N];
bool brage[M], vis[N];
vector<int> ans[N];

void add_edge(int x, int y) {
    edge[cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
}

void tarjan(int x, int last_edge) {
    dfn[x] = low[x] = ++num;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v, i);
            low[x] = min(low[x], low[v]);
            if (low[v] > dfn[x])
                brage[i] = brage[i ^ 1] = true;
        } else if (i != (last_edge ^ 1))
            low[x] = min(low[x], dfn[v]);
    }
    return;
}

void dfs(int x, int dcc) {
    vis[x] = true;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (brage[i] || vis[v])
            continue;
        ans[dcc].push_back(v);
        dfs(v, dcc);
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    int u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, -1);
    int dcc = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dcc++;
            ans[dcc].push_back(i);
            dfs(i, dcc);
        }
    }
    printf("%d\n", dcc);
    for (int i = 1; i <= dcc; i++) {
        printf("%d ", ans[i].size());
        for (auto one : ans[i])
            printf("%d ", one);
        printf("\n");
    }
    return 0;
}