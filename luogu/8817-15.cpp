#include <cstdio>
#include <vector>
using namespace std;

const int N = 2510;
vector<int> edge[N];
int val[N], n, m, k, start;
bool vis[N][N];

void DFS(int x, int fa, int step) {
    if (step > k + 1)
        return;
    vis[start][x] = true;
    for (int i = 0; i < edge[x].size(); i++) {
        int v = edge[x][i];
        if (v == fa || vis[start][v])
            continue;
        DFS(v, x, step + 1);
    }
    return;
}

int main() {
    int x, y;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 2; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        start = i;
        DFS(i, 0, 0);
    }
    int ans = 0;
    for (int a = 2; a <= n; a++)
        for (int b = 2; b <= n; b++)
            for (int c = 2; c <= n; c++)
                for (int d = 2; d <= n; d++) {
                    if (a == b || a == c || a == d || b == c || b == d || c == d)
                        continue;
                    if (vis[1][a] && vis[a][b] && vis[b][c] && vis[c][d] && vis[d][1]) {
                        ans = max(ans, val[a] + val[b] + val[c] + val[d]);
                    }
                }

    printf("%d", ans);
    return 0;
}