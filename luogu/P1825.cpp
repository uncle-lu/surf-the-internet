#include <iostream>
using namespace std;
const int Nmax = 310;
char arr[Nmax][Nmax]; // 310
bool vis[Nmax][Nmax];
int ans = 9999999;
int N, M;
void dfs(int x, int y, int step) {
    if (x < 0 || y < 0 || x >= N || y >= M || arr[x][y] == '#' || vis[x][y] || step > ans) { // M
        return;
    }
    if (arr[x][y] == '=') {
        ans = min(ans, step);
        return;
    }
    vis[x][y] = true; // 标记前移
    if (arr[x][y] >= 'A' && arr[x][y] <= 'Z') {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == arr[x][y]) {
                    if (!(i == x && j == y) && !vis[i][j]) { // !vis[i][j]
                        dfs(i, j, step);
                    }
                }
            }
        }
    }
    dfs(x + 1, y, step + 1);
    dfs(x - 1, y, step + 1);
    dfs(x, y + 1, step + 1);
    dfs(x, y - 1, step + 1);
    vis[x][y] = false;
}

int main() {
    freopen("in", "r", stdin);
    cin >> N >> M;
    int ssi = 0, ssj = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '@') {
                ssi = i;
                ssj = j;
            }
        }
    }
    dfs(ssi, ssj, 0);
    cout << ans << endl;
}