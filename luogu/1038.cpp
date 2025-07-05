#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 110;
struct node {
    int v, val;
};
vector<node> edge[N];
int c[N], u[N], in[N], out[N];

int main() {
    int n, p;
    cin >> n >> p; // 点数量、边数量
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i]; // c[i]第i个点的初始值, u[i]第i个点的阈值
        if(!c[i])
            c[i] -= u[i];
    }
    for (int i = 1; i <= p; i++) {
        int u, v, val;
        cin >> u >> v >> val;
        edge[u].push_back((node){v, val}); // 增加一条边 u -> v (权值为val)
        in[v]++;                           // v的入度增加
        out[u]++;                          // u的出度增加
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0 && c[i] > 0)
            qu.push(i);
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int v = edge[now][i].v, val = edge[now][i].val;
            in[v]--;
            c[v] += val * c[now];
            if (in[v] == 0 && c[v] > 0)
                qu.push(v);
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
        if (out[i] == 0 && c[i] > 0) {
            cout << i << " " << c[i] << endl;
            flag = true;
        }
    if (!flag)
        cout << "NULL";
    return 0;
}