#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

const int N = 2e5 + 10;
struct node {
    int v, next;
} edge[N * 2];
int cnt, n, m, scc_cnt, tot, top, sta[N], head[N], dfn[N], low[N], scc[N], line[N], ans[N];
bool vis[N];
std::vector<int>in_scc[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return ;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    line[tot] = x;
    vis[x] = true;
    sta[++top] = x;
    for(int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[x] = std::min(low[x], low[v]);
        } else if(vis[v])
            low[x] = std::min(low[x], dfn[v]);
    }
    if(low[x] == dfn[x]) {
        int v;
        scc_cnt++;
        do {
            v = sta[top--];
            vis[v] = false;
            scc[v] = scc_cnt;
            in_scc[scc_cnt].push_back(v);
        } while(v != x);
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        char ta, tb;
        int a, b;
        std::cin >> ta >> a >> tb >> b;
        // 0, 1 / 2[+1], 3[-1] / 4[+2], 5[-2] / 6[+3], 7[-3]
        add_edge(a * 2 ^ (ta == '+' ? 1 : 0), b * 2 ^ (tb == '+' ? 0 : 1));
        add_edge(b * 2 ^ (tb == '+' ? 1 : 0), a * 2 ^ (ta == '+' ? 0 : 1));
    }
    for(int i = 1; i <= m * 2; i++)  
        if (!dfn[i])
            tarjan(i);
    bool flag = true;
    for(int i = 1; i <= m; i++) 
        if(scc[i * 2] == scc[i * 2 ^ 1]) {
            flag = false;
            break;
        }
    if(!flag) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= tot; i++) {
        if(vis[line[i]/2])continue; 
        for(int x : in_scc[scc[line[i]]]) {
            
        }
    }
}