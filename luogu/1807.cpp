#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {   // 边的结构
    int v, val; // v 终点; val 边权;
};
const int N = 1510;
vector<node> edge[N];
bool vis[N];
int in[N], F[N];

int main() {
	//freopen("in","r",stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        in[y]++;
        edge[x].push_back((node){y, val});
    }
    for(int i = 1; i<=n; i++) // 将权值变为负，存在负边权
        F[i] = -1e9;
    F[1] = 0;
    vis[1] = true;
    queue<int> qu;               // 待搜索的队列（拓扑队列）
    for (int i = 1; i <= n; i++) // 枚举所有入度为0的点加入队列
        if (in[i] == 0)
            qu.push(i);
    while (!qu.empty()) { // 当队列不为空时，继续扩展所有的队列中的元素,往下走
        int now = qu.front();
        qu.pop();
        for (int i = 0; i < edge[now].size(); i++) { // 枚举所有以now为起点的边
            int v = edge[now][i].v;
            int val = edge[now][i].val; // now的第i条边的情况
                                    // v: 终点 , val 是 now -> v 的边的边权
            if (vis[now]) {
                F[v] = max(F[v], F[now] + val); // 检查 v 的路径取一个最优值
                vis[v] = true;
            }
            in[v]--; // 终点的入度减少
            if (in[v] == 0)
                qu.push(v);
        }
    }
    if (!vis[n])
        cout << -1;
    else
        cout << F[n];
    return 0;
}