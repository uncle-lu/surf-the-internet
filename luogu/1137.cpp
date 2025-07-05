#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

const int N = 100010;
std::vector<int> edge[N];
int n, m, in[N], F[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        in[v]++;
    }
    std::queue<int> qu;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) {
            qu.push(i);
            F[i] = 1;
        }
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (auto v : edge[now]) {
            F[v] = std::max(F[v], F[now] + 1);
            in[v]--;
            if (in[v] == 0)
                qu.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", F[i]);
    return 0;
}