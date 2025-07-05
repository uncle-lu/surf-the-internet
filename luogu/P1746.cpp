#include <cstdio>
#include <queue>
using namespace std;

const int N = 1010; // 坐标大小
struct node {
    int x, y, step;
} Start, End;
char maps[N][N]; // 地图样式
bool vis[N][N];
int x_turn[4] = {0, 0, 1, -1}; // 行的增量
int y_turn[4] = {1, -1, 0, 0};
// (x, y) -> (x + x_turn[0], y + y_turn[0]) -> 向右移动一位
// (x, y) -> (x + x_turn[2], y + y_turn[2]) -> 向下移动一位
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("\n%s", maps[i] + 1);
    scanf("%d %d %d %d", &Start.x, &Start.y, &End.x, &End.y);
    queue<node> qu;
    qu.push(Start);
    vis[Start.x][Start.y] = true;
    while (!qu.empty()) {
        node now = qu.front();
        qu.pop();
        if (now.x == End.x && now.y == End.y) {
            printf("%d", now.step);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
            if(xx < 1 || yy < 1 || xx > n || yy > n || vis[xx][yy] || maps[xx][yy] == '1')
                continue;
            vis[xx][yy] = true;
            qu.push((node){xx, yy, now.step + 1});
        }
    }
    return 0;
}