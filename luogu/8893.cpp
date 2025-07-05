#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e3*5;
vector<int>edge[N];
int dis[N], in[N]; // dis为天数, in为入度

int main() {
    int n, k, p, temp, r;
    cin >> n >> k >> p;
    dis[k] = -1;
    queue<int>qu;
    for(int i = 1; i<=p; i++) { // p个起始点
        cin >> temp;
        qu.push(temp);
        dis[temp] = 0;
    }
    cin >> r;
    for(int i = 1; i <= r; i++) {
        int v, s;
        cin >> v >> s;
        in[v] = s; // v的入度为s，存在s个题的前提
        for(int j = 1; j<=s; j++) {
            cin >> temp;
            edge[temp].push_back(v); // 从temp -> v的边
        }
    }
    while(!qu.empty()) {
        int now = qu.front(); // 取出队首
        qu.pop();
        for(int i = 0; i < edge[now].size(); i++) {
            int v = edge[now][i];
            in[v]--; // 题目v的依赖减少 => 已经做掉now了
            if(in[v] == 0) { // 说明要求被推荐的题已经全部做完了
                dis[v] = dis[now] + 1;
                qu.push(v);
            }
        }
    }
    cout << dis[k];
    return 0;
}