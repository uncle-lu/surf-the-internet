#include <cstdio>

char str[50];
bool vis[10][10];
int ans;

bool check(int x, int y) {
    if (x < 1 || x > 7 || y < 1 || y > 7 || vis[x][y])
        return false;
    return true;
}

void DFS(int sit, int x, int y) {
    if (sit == 48 || (x == 7 && y == 1)) {
        ans += (x == 7 && y == 1 && sit == 48) ? 1 : 0;
        return;
    }
    if (check(x + 1, y) && check(x - 1, y) && !check(x, y - 1) && !check(x, y + 1))
        return;
    if (check(x, y + 1) && check(x, y - 1) && !check(x - 1, y) && !check(x + 1, y))
        return;
    vis[x][y] = true;
    if ((str[sit] == 'D' || str[sit] == '?') && check(x + 1, y))
        DFS(sit + 1, x + 1, y);
    if ((str[sit] == 'U' || str[sit] == '?') && check(x - 1, y))
        DFS(sit + 1, x - 1, y);
    if ((str[sit] == 'L' || str[sit] == '?') && check(x, y - 1))
        DFS(sit + 1, x, y - 1);
    if ((str[sit] == 'R' || str[sit] == '?') && check(x, y + 1))
        DFS(sit + 1, x, y + 1);
    vis[x][y] = false;
    return;
}

int main() {
    scanf("%s", str);
    DFS(0, 1, 1);
    printf("%d", ans);
    return 0;
}