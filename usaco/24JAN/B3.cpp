#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5*2+10;
int line[N], d[N], D[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &line[i]);
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        d[i] = line[i] - line[i-1];
        D[i] = d[i] - d[i-1];
        cnt += abs(D[i]);
    }
    printf("%d", cnt);
    return 0;
}