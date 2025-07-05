#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e5 + 10, Mod = 1e9 + 7;
struct node {
    int v, next;
} edge[N * 2];
long long int F[N][4];
int head[N], tong[N], cnt, n, k;

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x, int fa) {
    if(tong[x])
        F[x][tong[x]] = 1;
    else
        F[x][1] = F[x][2] = F[x][3] = 1;
    for(int i = head[x]; ~i; i = edge[i].next){
        int v = edge[i].v;
        if(v == fa) continue;
        DFS(v, x);
        F[x][1] = F[x][1] * (F[v][2] + F[v][3]) % Mod;
        F[x][2] = F[x][2] * (F[v][1] + F[v][3]) % Mod;
        F[x][3] = F[x][3] * (F[v][1] + F[v][2]) % Mod;
    }
    return ;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= k; i++) {
        int sit, c;
        scanf("%d %d", &sit, &c);
        tong[sit] = c;
    }
    DFS(1, 0);
    printf("%lld", tong[1] ? F[1][tong[1]] % Mod : (1LL * F[1][1] + F[1][2] + F[1][3]) % Mod);
    return 0;
}