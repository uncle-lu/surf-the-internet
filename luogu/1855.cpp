#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 210;
int F[N][N];

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= n; i++) {
        int mi, ti;
        scanf("%d %d", &mi, &ti);
        for(int j = m; j >= mi; j--)
            for(int k = t; k >= ti; k--)
                F[j][k] = max(F[j][k], F[j - mi][k - ti] + 1);
    }
    printf("%d", F[m][t]);
    return 0;
}