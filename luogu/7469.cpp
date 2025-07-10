#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>

using ull = unsigned long long int;
const int N = 3010;
const int p1 = 998244353, p2 = 8530771;
int n, cnt;
char str1[N], str2[N];
std::pair<ull, ull> line[N * N];

int main() {
    scanf("%d\n%s\n%s", &n, str1, str2);
    for (int l = 0; l < n; l++) {
        int curr = 0;
        ull sum1 = 1, sum2 = 1;
        for (int r = l; r < n; r++, curr++) {
            while (curr < n && str1[curr] != str2[r])
                curr++;
            if (curr == n)
                break;
            sum1 = sum1 * p1 + (str2[r] - 'a');
            sum2 = sum2 * p2 + (str2[r] - 'a');
            line[++cnt] = std::make_pair(sum1, sum2);
        }
    }
    std::sort(line + 1, line + 1 + cnt);
    int ans = 1;
    for (int i = 2; i <= cnt; i++)
        if (line[i] != line[i - 1])
            ans++;
    printf("%d", ans);
    return 0;
}