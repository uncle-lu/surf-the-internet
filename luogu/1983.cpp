#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

const int N = 1e3 + 10;
int n, m, du[N], dis[N];
std::vector<int> G[N];
bool vis[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int num, temp, top;
        std::vector<int> line, target;
        scanf("%d", &num);
        scanf("%d", &temp);
        top = temp;
        line.push_back(temp);
        for (int i = 2; i <= num; i++) {
            scanf("%d", &temp);
            while (temp != top + 1)
                target.push_back(++top);
            line.push_back(temp);
            top = temp;
        }
        for (auto u : line)
            for (auto v : target) {
                if(vis[u][v])continue;
                vis[u][v] = true;
                G[u].push_back(v);
                du[v]++;
            }
    }
    std::queue<int> qu;
    for (int i = 1; i <= n; i++)
        if (!du[i]) {
            qu.push(i);
            dis[i] = 1;
        }
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (auto v : G[now]) {
            dis[v] = std::max(dis[v], dis[now] + 1);
            du[v]--;
            if (!du[v])
                qu.push(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, dis[i]);
    printf("%d", ans);
    return 0;
}