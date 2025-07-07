#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 3e5 + 10, N = 3e5 + 10;
struct node {
    int v, next;
} edge[M * 2];
int n, m, cnt, num, dcc_cnt, dcc[N], head[N], dfn[N], low[N];
bool is_brige[M * 2];

void add_edge(int x, int y) {
    edge[cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
    return;
}

void tarjan(int x, int last_edge) {
    dfn[x] = low[x] = ++ num;
    for(int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v, i);
            low[x] = min(low[x], low[v]);
            if(low[v] > dfn[x])
                is_brige[i] = is_brige[i ^ 1] = true;
        } else if(i != (last_edge ^ 1))
            low[x] = min(low[x], dfn[v]);
    }
    return ;
}

void dfs(int x) {
    dcc[x] = dcc_cnt;
    for(int i = head[x]; ~i; i = edge[i].next) {
        if(is_brige[i] || dcc[edge[i].v])continue;
        dfs(edge[i].v);
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i, -1);

    for(int i = 1; i <= n; i++)
        if(!dcc[i])     {
            dcc_cnt++;
            dfs(i);
        }
    
    for(int i = 1; i <= n; i++)
    return 0;
}