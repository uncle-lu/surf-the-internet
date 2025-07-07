#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10, M = 8e3 + 10;
struct node {
    int v, next;
} edge[2 * M];
int n, p, r, cnt, scc_cnt, num, top, tot, pv[N], head[N], dfn[N], low[N], scc[N], scc_num[N], sta[N], scc_min[N], scc_in[N];
bool vis[N];

void add_edge(int x, int y) {
    edge[cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
    return;
}

void dfs(int x){
    if(vis[x])return ;
    vis[x] = true;tot++;
    for(int i = head[x]; ~i; i = edge[i].next)
        dfs(edge[i].v);
    return ;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    vis[x] = true;
    sta[++top] = x;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (vis[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x]) {
        int v;
        scc_cnt++;
        do {
            v = sta[top--];
            scc[v] = scc_cnt;
            if(pv[v] != -1)
                scc_min[scc_cnt] = min(scc_min[scc_cnt], pv[v]);
            vis[v] = false;
            scc_num[scc_cnt]++;
        } while (v != x);
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(pv, -1, sizeof(pv));
    memset(scc_min, 0x7f, sizeof(scc_min));
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= p; i++) {
        int tf, ts;
        scanf("%d %d", &tf, &ts);
        pv[tf] = ts;
    }
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    for(int i = 1; i <= n; i++)
        if(pv[i] != -1)
            dfs(i);
    if(tot < n) {
        for(int i = 1;i <= n; i++)
            if(!vis[i]) {
                printf("NO\n%d",i);
                return 0;
            }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    int ans = 0;
    for(int t = 1; t <= n; t++) 
        for(int i = head[t]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if(scc[t] == scc[v])continue;
            scc_in[scc[v]]++;
        }
    for(int i = 1; i <= scc_cnt; i++)
        if(scc_in[i] == 0)
            ans += scc_min[i];
    printf("YES\n%d", ans);
    return 0;
}
