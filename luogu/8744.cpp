#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[N];
int head[N], f[N], cnt, n;

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dfs(int x) {
    int size = 0;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        dfs(v);
        f[x] = std::max(f[v], f[x]);
        size++;
    }
    f[x] += size;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        add_edge(temp, i);
    }
    dfs(1);
    printf("%d", f[1]);
    return 0;
}