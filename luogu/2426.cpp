#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 110;
int line[N], F[N][N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++)
        F[i][i] = line[i];
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            F[i][j] = max(F[i][i] + F[i + 1][j], F[j][j] + F[i][j - 1]);
            for (int k = i; k <= j; k++)
                F[i][j] = max({F[i][j], abs(line[k] - line[j]) * abs(j - k + 1) + F[i][k - 1],
                               abs(line[i] - line[k]) * abs(k - i + 1) + F[k + 1][j]});
        }
    printf("%d", F[1][n]);
    return 0;
}