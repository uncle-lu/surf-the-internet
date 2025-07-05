#include <cstdio>
#include <algorithm>

const int N = 1010;
int line[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    std::sort(line+1, line+1+n);
    int mx = 1, sum = line[1], ans = 0;
    for(int mi = 1; mi <= n; mi++) {// 指向最小值的指标
        while(mx + 1 <= n && line[mx + 1] - line[mi] <= k) {
            // 1. 指向最大值的指标（下一位）在范围内
            // 2. 最大值减最小值符合条件
            // 因为符合条件 => 扩大[mi, mx]的范围 mx向后增加
            mx++;
            sum += line[mx];
        }
        // 当不在while循环时说明 => line[mx+1]-line[mi] 不符合条件 line[mx+1] 太大了
        ans = std::max(ans, sum); // 记录mi时，最大的mx产生的答案
        sum -= line[mi]; // 减去和 => mi增加 => line[mi] 变大 => line[mx+1]-line[mi]符合条件
    }
    printf("%d", ans);
    return 0;
}