#include <cstdio>
#include <algorithm>

const int N = 2010;
long long int F[N][N];
int line[N], n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for(int i = 1; i <= n; i++)
        F[i][i] = 1ll * line[i] * n;
    for(int len = 2; len <= n; len++)
        for(int i = 1; i <= n - len + 1; i ++) {
            int j = i + len - 1;
            F[i][j] = std::max(
                F[i + 1][j] + line[i] * (n - len + 1),
                F[i][j-1] + line[j] * (n - len + 1)
            );
        }
    printf("%lld", F[1][n]);
    return 0;
}