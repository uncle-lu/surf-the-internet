#include <algorithm>
#include <climits>
#include <cstdio>
#include <queue>
#include <vector>

const int N = 5e5 + 10;
std::vector<int> edge[N];
int n, m,  in[N];
long long int dis[N], a[N];

int main() {
    scanf("%d %d", &n, &m);
    long long int x1 = LLONG_MAX, x2 = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        dis[i] = a[i];
        if (a[i] <= x1)
            x2 = x1, x1 = a[i];
        else if (a[i] < x2)
            x2 = a[i];
    }
    long long int ans = 2 * (x1 + x2);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        in[v]++;
    }
    std::queue<int> qu;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            qu.push(i);
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (auto v : edge[now]) {
            ans = std::min(ans, dis[now] + a[v]);
            dis[v] = std::min(dis[v], dis[now]);
            in[v]--;
            if (in[v] == 0)
                qu.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (in[i])
            ans = 0;
    printf("%lld", ans);
    return 0;
}