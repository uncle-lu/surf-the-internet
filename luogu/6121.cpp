#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5+10;
vector<int>edge[N];
bool vis[N], ans[N];
int line[N];
int father[N];

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edge[y].push_back(x);
        edge[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) // 取消的顺序
        scanf("%d", &line[i]);
    int cnt = 0; // 记录集合的数量
    for(int i = n; i >= 1; i--) { // 倒序枚举取消 => 激活的顺序
        int x = line[i]; // 激活x
        vis[x] = true; // 激活
        father[x] = x; cnt++;
        for(int j = 0; j < edge[x].size(); j++) {
            int v = edge[x][j];
            if(vis[v]) {
                int tx = find_father(x), ty = find_father(v);
                if(tx != ty) { // 两个不同的集合
                    father[ty] = tx;
                    cnt--; // 集合数量减少
                }
            }
        }
        if(cnt > 1) 
            ans[i] = false;
        else
            ans[i] = true;
    }
    for(int i = 1; i <= n; i++) 
        if(ans[i])
            printf("YES\n");
        else
            printf("NO\n");
    return 0;
}