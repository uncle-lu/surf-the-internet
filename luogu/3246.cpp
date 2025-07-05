#include <algorithm>
#include <cstdio>

int F[300][300];
int ans, n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &F[i][i]);
        ans = std::max(ans, F[i][i]);
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l; k <= r - 1; k++)
                if (F[l][k] == F[k + 1][r] && F[l][k])
                    F[l][r] = std::max(F[l][r], F[l][k] + 1);
            ans = std::max(ans, F[l][r]);
        }
    }

    printf("%d", ans);
    return 0;
}