#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 410;

int F[N][N];

int main() {
    int h, t, n;
    scanf("%d %d %d" ,&h, &t, &n);
    for(int i = 1; i <= n; i++) {
        int hi, ti, ki;
        scanf("%d %d %d", &hi, &ti, &ki);
        for(int j = h; j >= hi; j--)
            for(int k = t; k >= ti; k--)
                F[j][k] = max(F[j][k], F[j - hi][k - ti] + ki);
    }
    printf("%d", F[h][t]);
    return 0;
}