#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 20;
int line[N];
long long int f[N][N][N];
// f[l][r][k] 在[l,r]范围内使用了k个乘号的最大值
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++)
        f[i][i][0] = line[i];
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1; // 区间[l, r]
            for (int t = 0; t <= min(k, len-1); t++) {
                for (int m = l; m < r; m++) { // 分为 [l, m] 与 [m+1, r] 两个区间
                    for (int t1 = 0; t1 <= t && (m - l + 1) > t1; t1++) {
                        if(r-(m+1) < t-t1) // 判断可行范围，要将不合法的范围去掉。
                            continue;
                        f[l][r][t] = max(f[l][r][t], f[l][m][t1] + f[m + 1][r][t - t1]);
                        if (t - t1 != 0)
                            f[l][r][t] = max(f[l][r][t], f[l][m][t1] * f[m + 1][r][t - t1 - 1]);
                        if (t1 != 0)
                            f[l][r][t] = max(f[l][r][t], f[l][m][t1 - 1] * f[m + 1][r][t - t1]);
                    }
                }
            }
        }
    }
    printf("%lld", f[1][n][k]);
    return 0;
}