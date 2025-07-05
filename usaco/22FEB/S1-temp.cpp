#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
typedef long long LL;
typedef double db;
using namespace std;

inline int read()
{
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int MAXN = 510;
int n, a[MAXN][MAXN], f[MAXN][MAXN];

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][a[i][j]] = true;
            if (a[i][j] == i)
                break;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] |= (f[i][k] & f[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (f[i][a[i][j]] && f[a[i][j]][i])
            {
                printf("%d\n", a[i][j]);
                break;
            }
    return 0;
}
