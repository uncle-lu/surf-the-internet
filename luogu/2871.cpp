#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 12890;

int F[N];

int main() {
    int n, m, w, d;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w, &d);
        for(int j = m; j >= w; j--)
            F[j] = max(F[j], F[j - w] + d);
    }
    printf("%d", F[m]);
    return 0;
}