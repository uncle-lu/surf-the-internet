#include <bits/stdc++.h>
using namespace std;

const int M = 5e3 * 2 + 10, N = 160;
struct node {
    int v, next;
} edge[M];
int n, m, cnt, num, head[N], dfn[N], low[N];
vector<pair<int, int> >ans;

void add_edge(int x, int y) {
    edge[cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
    return ;
}

void tarjan(int x, int last_edge) {
    dfn[x] = low[x] = ++num;
    for(int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(!dfn[v]) {
            tarjan(v, i);
            low[x] = min(low[x], low[v]);
            if(low[v] > dfn[x]) 
                ans.push_back(make_pair(min(x,v), max(x,v)));
        }
        else if(i != (last_edge^1))
            low[x] = min(low[x], dfn[v]);
    }
    return ;
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
    tarjan(1, -1);
    sort(ans.begin(), ans.end());
    for(auto one: ans)
        printf("%d %d\n", one.first, one.second);
    return 0;
}