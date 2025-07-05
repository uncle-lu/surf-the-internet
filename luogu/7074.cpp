#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e3 + 10;
int maps[N][N];
long long int f[N][N][2];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &maps[i][j]);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            f[i][j][1] = f[i][j][0] = -1e18;
    f[1][1][0] = f[1][1][1] = maps[1][1];
    //[0] 从上往下, [1] 从下往上
    for (int i = 1; i <= m; i++) { // 枚举每一列
        for (int j = 1; j <= n && i != 1; j++) {
            f[j][i][0] = max(f[j][i - 1][0], f[j][i - 1][1]) + maps[j][i];
            f[j][i][1] = max(f[j][i - 1][0], f[j][i - 1][1]) + maps[j][i];
        }
        for (int j = n-1; j >= 1; j--)
            f[j][i][0] = max(f[j][i][0], f[j + 1][i][0] + maps[j][i]);
        for (int j = 2; j <= n; j++)
            f[j][i][1] = max(f[j][i][1], f[j - 1][i][1] + maps[j][i]);
    }
    printf("%lld", max(f[n][m][1], f[n][m][0]));
    return 0;
}