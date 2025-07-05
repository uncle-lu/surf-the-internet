#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 510;
int d[N][N], line[N], p, f, c;

int main() {
    memset(d, 0x3f, sizeof(d));
    scanf("%d %d %d", &p, &f, &c);
    for (int i = 1; i <= f; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= p; i++)
        d[i][i] = 0;
    for (int i = 1; i <= c; i++) {
        int x, y, val;
        scanf("%d %d %d", &x, &y, &val);
        d[x][y] = val;
        d[y][x] = val;
    }
    for (int k = 1; k <= p; k++)
        for (int x = 1; x <= p; x++)
            for (int y = 1; y <= p; y++)
                d[x][y] = min(d[x][k] + d[k][y], d[x][y]);

    int ans = 0x7f7f7f7f, sit;
    for (int i = 1; i <= p; i++) {
        int sum = 0;
        for (int j = 1; j <= f; j++)
            sum += d[i][line[j]];
        if (ans > sum) {
            ans = sum;
            sit = i;
        }
    }
    printf("%d", sit);
    return 0;
}