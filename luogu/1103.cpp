#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
struct node {
    int x, y;
};
bool cmp(node a, node b) {
    return a.x < b.x;
}
node line[N];
int f[N][N], g[N][N];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &line[i].x, &line[i].y);
    sort(line + 1, line + 1 + n, cmp);
    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i <= n; i++)
        f[i][i - 1] = 0;
    for (int i = 1; i <= n; i++)               // 处理到第i本
        for (int j = 0; j <= min(i, k); j++) { // 拿走j本
            for (int t = j + 1; t >= 1; t--)
                f[i][j] = min(f[i][j], f[i - t][j - t + 1] + abs(line[i].y - line[i - t].y));
        }
    /*
    for(int i=1; i<=n; i++)
        printf("%d ", line[i].y);
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            printf("%d ", f[i][j]);
        printf("\n");
    }
    */
    int ans = 0x7f7f7f7f;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, f[n][i]);
        if (n - i > 0)
            ans = min(ans, f[n - i][k - i]);
    }
    printf("%d", ans);
    return 0;
}