#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;

int F[N];

int main() {
    int v, n, c;
    scanf("%d %d %d", &v, &n, &c);
    for(int i = 1; i <= n; i++) {
        int k, m;
        scanf("%d %d", &k, &m);
        for(int j = c; j >= m; j--)
            F[j] = max(F[j], F[j - m] + k);
    }
    int ans = -1;
    for(int i = 0; i <= c; i++)
        if(F[i] >= v) {
            ans = c - i;
            break;
        }
    if(ans == -1)
        printf("Impossible");
    else
        printf("%d", ans);
    return 0;
}