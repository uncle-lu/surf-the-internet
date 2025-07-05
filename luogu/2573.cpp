#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e5 + 10, M = 1e6 * 2 + 10;
struct node {
    int v, next, val;
}edge[M];
struct e { // 从1开始可以枚举到的所有边
    int u, v, val;
}E[M];
int n, m, cnt, num, ans, head[N], h[N], fa[N];
bool vis[N];

int find_father(int x){
    return fa[x] == x ? x : fa[x] = find_father(fa[x]);
}

bool cmp(e a, e b){ // 排序看的是 正确性 => 先排终点高度高-->保证先滑到高度高的后续滑高度低的
    return h[a.v] > h[b.v] || (h[a.v] == h[b.v] && a.val < b.val);
}

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return ;
}

void dfs(int x) {
    vis[x] =  true;
    ans++;
    for(int i = head[x]; ~i; i = edge[i].next) { // 枚举从x开始能走到的点
        int v = edge[i].v;
        E[++num]=(e){x, v, edge[i].val}; // 记录(x, v)的边，加入滑雪路径的备选
        if(vis[v])continue;
        dfs(v);
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for(int i = 1; i <= m; i++)  {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        if(h[u] >= h[v])
            add_edge(u, v, val);
        if(h[v] >= h[u])
            add_edge(v, u, val);
    }
    dfs(1);
    std::sort(E+1, E+1+num, cmp);
    long long sum = 0;
    for(int i = 1; i <= num ;i++) { // 生成 最小生成树 -> 滑雪路径
        int fax = find_father(E[i].u), fay = find_father(E[i].v);
        if(fax != fay) {
            sum += E[i].val;
            fa[fay] = fax;
        }
    }
    printf("%d %lld", ans, sum);
    return 0;
}