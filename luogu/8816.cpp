#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    int x, y;
};
bool cmp1(node a, node b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dis(node a, node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
const int N = 510;
node line[N];
int f[N][N]; // f[i][j] 到第i个点，用了j个耗点  剩多少个耗点

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &line[i].x, &line[i].y);
    sort(line + 1, line + 1 + n, cmp1);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++)
            f[i][j] = j+1; // 初始时，直接把j个点接在前面。
    }
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t <= k; t++) {
            for (int j = 1; j < i; j++) {
                if (line[i].y < line[j].y || dis(line[i], line[j]) - 1 > t)
                    continue;
                f[i][t] = max(f[i][t], f[j][t-dis(line[i], line[j])+1] + dis(line[i], line[j]));
            }
        }
    }
    
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if(mx < f[i][k])
            mx = f[i][k];
    }
    printf("%d", mx);
    return 0;
}