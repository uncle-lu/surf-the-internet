#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int v[21], F[N];

int main() {
    int m;
    for(int i = 1; i <= 20; i++) 
        v[i] = i * i * i *i;
    scanf("%d", &m);
    memset(F, 0x7f, sizeof(F));
    F[0] = 0;
    for(int i = 1; i <= 20; i++)
        for(int j = v[i]; j <= m; j++)
            F[j] = min(F[j], F[j - v[i]] + 1);
    printf("%d", F[m]);
    return 0;
}