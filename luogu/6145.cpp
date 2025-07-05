#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int v, val;
};
const int N = 1e5 + 10;
vector<node> edge[N];
int F[N], in[N];

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) // 读入每个牛的初始时间
        cin >> F[i];
    for (int i = 1; i <= c; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        edge[u].push_back((node){v, val}); // 读入每个限制 v必须在u之后val天进行。
        in[v]++; // v的入度增加
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) // 当i的入度为0时 => 没有限制
            qu.push(i);
    while (!qu.empty()) {
        int now = qu.front(); // 取出队首
        qu.pop();
        for (int i = 0; i < edge[now].size(); i++) { //枚举队首的所有之后的点
            int v = edge[now][i].v, val = edge[now][i].val;
            in[v]--; // 终点入度减少
            F[v] = max(F[v], F[now] + val); // 取最大值 => 满足任何条件，在各种限制之后进行挤奶
            if (in[v] == 0) // 判断入度为0 => 加入队列
                qu.push(v);
        }
    }
    for (int i = 1; i <= n; i++) // 输入每个挤奶时间的最小实现值
        cout << F[i] << endl;
    return 0;
}