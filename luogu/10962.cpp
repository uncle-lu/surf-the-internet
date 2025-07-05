#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e4 + 10;
struct node {
    int v, next, val;
} edge[2 * N];
int n, cnt, head[N], f[N][3], g[N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    edge[cnt].val = val;
    head[x] = cnt;
    return;
}

void init() {
    memset(head, -1, sizeof(head));
    memset(f, 0, sizeof(f));
    cnt = 0;
}

void dfs1(int x, int fa) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (fa == v)
            continue;
        dfs1(v, x);
        if (f[x][0] < f[v][0] + edge[i].val) {
            f[x][1] = f[x][0];
            f[x][0] = f[v][0] + edge[i].val;
            g[x] = v;
        } else
            f[x][1] = std::max(f[x][1], f[v][0] + edge[i].val);
    }
    return;
}

void dfs2(int x, int fa) {
    for(int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if(fa == v)
            continue;
        if(g[x] == v) 
            f[v][2] = std::max(f[x][2], f[x][1]) + edge[i].val;
        else
            f[v][2] = std::max(f[x][2], f[x][0]) + edge[i].val;
        dfs2(v, x);
    }
    return ;
}

int main() {
    while (~scanf("%d", &n)) {
        init();
        for (int i = 2; i <= n; i++) {
            int v, val;
            scanf("%d %d", &v, &val);
            add_edge(i, v, val);
            add_edge(v, i, val);
        }
        dfs1(1, 0);
        dfs2(1, 0);
        for(int i = 1; i <= n; i++)
            printf("%d\n", std::max(f[i][2],f[i][0]));
    }
    return 0;
}