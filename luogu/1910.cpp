#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;

int F[N][N];

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        for(int j = m; j >= b; j--)
            for(int k = x; k >= c; k--)
                F[j][k] = max(F[j][k], F[j - b][k - c] + a);
    }

    printf("%d", F[m][x]);

    return 0;
}