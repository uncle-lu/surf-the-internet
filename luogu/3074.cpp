#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
vector<int> edge[N];
int F[N], dis[N], in[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> F[i]; // 第i头牛挤奶耗费的时间
        dis[i] = F[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v); // 存在一条依赖 u -> v，只有 u 挤完了才能挤 v
        in[v]++;
    }
    queue<int>qu;
    for(int i = 1; i<=n; i++) 
        if(!in[i]) 
            qu.push(i);

    while(!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for(auto v : edge[now]) {
            dis[v] = max(dis[v], dis[now] + F[v]);
            in[v]--;
            if(!in[v])
                qu.push(v);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n;i ++)
        ans = max(ans, dis[i]);
    cout << ans;

    return 0;
}