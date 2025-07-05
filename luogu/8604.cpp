#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
vector<int> edge[N]; // 定义了N个vector => edge[i] 第i个vector
// edge[x] => 一个边数组 从 x 为起点到 edge[x][i] 的边
// edge[x] 是一个vector数组 存了x为起点的所有边
int n, m;
bool vis[N]; // 记录是否访问过, 访问过就不访问

void DFS(int x) {                              // 站在第x点的位置，往下拓展
    for (int i = 0; i < edge[x].size(); i++) { // 枚举以x为起点的各个边
        int v = edge[x][i];
        if (vis[v]) // 如果vis[v]为true 说明v点已经访问过了。
            continue;
        vis[v] = true; // 记录v访问过了
        DFS(v); // 枚举v后续的所有情况，深搜站在v上进行后续的搜索
    }
    return;
}

int main() {
    int u, v, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        edge[u].push_back(v); // 在edge[u]数组中增加一个v (u -> v)的边
        edge[v].push_back(u); // 在edge[v]数组中增加一个u (v -> u)的边
    }
    cin >> u >> v;                 // 作为起点与终点
    memset(vis, false, sizeof(vis));
    vis[u] = true;
    DFS(u); // 在没有任何点取出的情况下，也访问不到。
    if(!vis[v]) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++) { // 枚举关键点
        if (i == u || i == v)
            continue;
        memset(vis, false, sizeof(vis)); // 清空vis数组
        vis[i] = true; vis[u] = true;
        DFS(u); // 重新开始从u开始深度优先枚举
        if (!vis[v]) // 如果将i去除后, v访问不到了，说明i是一个关键点
            ans++;
    }
    cout << ans;
    return 0;
}