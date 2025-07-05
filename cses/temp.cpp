#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define pre(i, b, a) for (int i = (b); i >= (a); i--)
#define mem(a, b) memset(a, b, sizeof a);
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
int n, m, du[N], front[N], dis[N], vis[N];
vector<int> g[N];
vector<int> ans;
queue<int> q;
void dfs(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (vis[v])
            continue;
        dfs(v);
    }
    return;
}
void topo() {
    rep(i, 1, n) {
        if (du[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            du[v]--;
            if (dis[u] != -1 && dis[v] < dis[u] + 1) {
                front[v] = u;
                dis[v] = dis[u] + 1;
            }
            if (du[v] == 0) {
                q.push(v);
            }
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        du[v]++;
    }
    rep(i, 2, n) dis[i] = -1;
    dfs(1);
    if (vis[n] == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    topo();
    for (int i = n; i != 1; i = front[i])
        ans.push_back(i);
    ans.push_back(1);
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}
