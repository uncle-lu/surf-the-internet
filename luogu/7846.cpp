#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e5 + 10, Mod = 1e9 + 7;
struct node {
    int v, next, val;
} edge[N * 2];
int head[N], cnt, n, r;
long long F[N][110], G[N][110];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    edge[cnt].val = val;
    head[x] = cnt;
    return;
}

void DFS(int x, int fa) {
    for (int i = 1; i <= r; i++) {
        F[x][i] = 1;
        G[x][i] = i;
    }
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == fa)
            continue;
        DFS(v, x);
        for (int w = 1; w <= r; w++) {
            if (edge[i].val == 0) {
                long long sum = 0, mi = 0x7f7f7f7f;
                for (int j = 1; j <= r; j++)
                    if (w != j) {
                        sum = (sum + F[v][j]) % Mod;
                        mi = std::min(mi, G[v][j]);
                    }
                F[x][w] = (F[x][w] * sum) % Mod;
                G[x][w] += mi;
            } else if (edge[i].val == 1) {
                long long sum = 0, mi = 0x7f7f7f7f;
                for (int j = 1; j <= r; j++) {
                    sum = (sum + F[v][j]) % Mod;
                    mi = std::min(mi, G[v][j]);
                }
                F[x][w] = (F[x][w] * sum) % Mod;
                G[x][w] += mi;
            } else {
                F[x][w] = F[x][w] * F[v][w] % Mod;
                G[x][w] += G[v][w];
            }
        }
    }
    return ;
}

int main() {
    bool flag = false;
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &r);
    for (int i = 1; i < n; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
        add_edge(v, u, val);
        if(val == 0)
            flag = true;
    }
    if(flag && r == 1) {
        printf("0 0");
        return 0;
    }
    DFS(1, 0);
    long long sum = 0, mi = 0x7f7f7f7f;
    for (int i = 1; i <= r; i++) {
        sum = (sum + F[1][i]) % Mod;
        mi = std::min(mi, G[1][i]);
    }
    printf("%lld %lld", sum, mi);
    return 0;
}