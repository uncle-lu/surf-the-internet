#include <cstdio>
#include <algorithm>

char maps[20][20];

int count(int x1, int y1, int x2, int y2) {
    int cnt = 0;
    for(int x = x1; x <= x2; x++)
        for(int y = y1; y <= y2; y++)
            cnt += maps[x][y] == '1';
    return cnt;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", maps[i] + 1);

    int ans = 0;
    for(int x1 = 1; x1 <= n; x1++) // (x1, y1) 左上角
        for(int y1 = 1; y1 <= m; y1++)
            for(int x2 = x1; x2 <= n; x2++) // (x2, y2) 右下角
                for(int y2 = y1; y2 <= m; y2++) // => 枚举了一个 子矩阵
                    if((x2 - x1 + 1) * (y2 - y1 + 1) == 2 * count(x1, y1, x2, y2))
                        ans = std::max(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
    
    printf("%d", ans);
    return 0;
}