#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 510;
vector<int> edge[N];
int in[N], u[N];
bool vis[N];

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v, s;
        cin >> u[i] >> s;
        for (int j = 1; j <= s; j++) {
            cin >> v;
            edge[u[i]].push_back(v);
            in[v]++;
        }
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++)
        if (in[u[i]] == 0) {
            qu.push(u[i]);
            vis[u[i]] = true;
        }
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int v = edge[now][i];
            in[v]--;
            if (in[v] == 0) {
                qu.push(v);
                vis[v] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (vis[u[i]])
            cnt++;
    if (cnt != n)
        cout << n - cnt;
    else
        cout << "YES";
    return 0;
}