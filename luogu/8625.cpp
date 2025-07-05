#include<cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e5 + 10;
struct node{
    int v, next;
}edge[2 * N];
int cnt, line[N], head[N];
long long int f[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return ;
}

void DFS(int x, int fa) {
    f[x] = line[x];
    for(int i = head[x]; ~i; i = edge[i].next) {
        if(edge[i].v == fa)continue;
        DFS(edge[i].v, x); 
        f[x] = std::max(f[x], f[x] + f[edge[i].v]);
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &line[i]);
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    DFS(1 ,0);
    long long int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = std::max(ans, f[i]);
    }
    printf("%lld", ans);
    return 0;
}