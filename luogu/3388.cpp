#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10, M = 2e5 + 10;
struct node {
    int v, next;
} edge[M];
int n, m, cnt, num, head[N], dfn[N], low[N];
vector<int> ans;

void add_edge(int x, int y) {
    edge[cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
}

void tarjan(int x, int last_edge) {
    int son = 0;
    bool is_cut = false;
    dfn[x] = low[x] = ++num;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v, i);
            son++;
            low[x] = min(low[x], low[v]);
            if (dfn[x] <= low[v])
                is_cut = true;
        } else if (i != (last_edge ^ 1))
            low[x] = min(low[x], dfn[v]);
    }
    if ((son >= 1 && last_edge != -1 && is_cut) || (son > 1 && last_edge == -1 && is_cut)) {
        ans.push_back(x);
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
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (auto one : ans)
        printf("%d ", one);
    return 0;
}