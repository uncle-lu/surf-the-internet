#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;
char line1[N], line2[N];
int target[5][5] = {
    {5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, 0},
};
int len1, len2, f[N][N];
int change(char x) {
    switch (x) {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    default:
        return 4;
    }
}
// f[i][j] 第1个串匹配到i与第2个串匹配到j时，获得的最大收益。
// f[i][j] 从f[i][j-1]与j; f[i-1][j]与i; f[i-1][j-1]与i,j
int main() {
    scanf("%d %s", &len1, line1 + 1);
    scanf("%d %s", &len2, line2 + 1);
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            f[i][j] = -10000;
    f[0][0] = 0;
    for (int i = 1; i <= len1; i++)
        f[i][0] = f[i - 1][0] + target[4][change(line1[i])];
    for (int i = 1; i <= len2; i++)
        f[0][i] = f[0][i - 1] + target[4][change(line2[i])];
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++) {
            f[i][j] = f[i - 1][j - 1] + target[change(line1[i])][change(line2[j])];
            f[i][j] = max(f[i][j], f[i - 1][j] + target[change(line1[i])][4]);
            f[i][j] = max(f[i][j], f[i][j - 1] + target[4][change(line2[j])]);
        }
    printf("%d", f[len1][len2]);
    return 0;
}