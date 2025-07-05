#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = 3e5 + 10;
struct Edge {
    int x, y, val;
    friend bool operator<(const Edge a, const Edge b) {
        return a.val > b.val;
    }
};
Edge eline[M];
struct node {
    int v, val, next;
};
node edge[2 * M];
int Father[N], head[N], col[N], F[N][30], dis[N][30], d[N];
int n, m, q, cnt;

int find_Father(int x) {
    return Father[x] == x ? x : Father[x] = find_Father(Father[x]);
}

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (col[v])
            continue;
        dis[v][0] = edge[i].val;
        F[v][0] = x;
        for (int j = 1; j <= 26; j++) {
            F[v][j] = F[F[v][j - 1]][j - 1];
            dis[v][j] = min(dis[v][j - 1], dis[F[v][j - 1]][j - 1]);
        }
        col[v] = col[x];
        d[v] = d[x] + 1;
        DFS(v);
    }
    return;
}

int Lca(int x, int y) {
    if (d[x] > d[y])
        swap(x, y);
    int mi = 0x7f7f7f7f;
    for (int i = 26; i >= 0; i--)
        if (d[F[y][i]] >= d[x]) {
            mi = min(mi, dis[y][i]);
            y = F[y][i];
        }
    if (x == y)
        return mi;
    for (int i = 26; i >= 0; i--)
        if (F[y][i] != F[x][i]) {
            mi = min(mi, min(dis[x][i], dis[y][i]));
            x = F[x][i];
            y = F[y][i];
        }
    mi = min(mi, min(dis[x][0], dis[y][0]));
    return mi;
}

int main() {
    memset(dis, 0x7f, sizeof(dis));
    memset(head, -1, sizeof(head));
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &eline[i].x, &eline[i].y, &eline[i].val);
    sort(eline + 1, eline + 1 + m);
    for (int i = 1; i <= n; i++)
        Father[i] = i;
    int tempcnt = 0;
    for (int i = 1; i <= m; i++) {
        int xx = find_Father(eline[i].x), yy = find_Father(eline[i].y);
        if (xx != yy) {
            Father[yy] = xx;
            tempcnt++;
            add_edge(eline[i].x, eline[i].y, eline[i].val);
            add_edge(eline[i].y, eline[i].x, eline[i].val);
            if (tempcnt == n - 1)
                break;
        }
    }
    tempcnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!col[i]) {
            for (int j = 0; j <= 26; j++) {
                F[i][j] = i;
            }
            col[i] = ++tempcnt;
            DFS(i);
        }
    }
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (col[x] != col[y])
            printf("-1\n");
        else
            printf("%d\n", Lca(x, y));
    }
    return 0;
}