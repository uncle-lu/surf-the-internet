#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 110;

int t[N], F[5010], ti[N], w[N];

int main() {
    int wky, wang, n, m, p, T;
    scanf("%d %d", &wky, &wang);
    p = wang / wky;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        t[i] = t[i] * p;
    }
    for(int i = 1; i <= m; i++) 
        scanf("%d %d", &ti[i], &w[i]);
    scanf("%d", &T);
    for(int i = 1; i <= m; i++)
        for(int j = T; j >= t[ti[i]]; j --) 
            F[j] = max(F[j], F[j - t[ti[i]]] + w[i]);
    
    printf("%d", F[T]);
    return 0;
}