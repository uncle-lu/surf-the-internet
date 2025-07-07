#include <cmath>
#include <cstdio>
#include <vector>

void func(int x, std::vector<int> &line) {
    line.push_back(x);
    for (int i = 2; i <= x; i++)
        while (x % i == 0) {
            line.push_back(x / i);
            x /= i;
        }
    return;
}

int solve(int x, int y) {
    std::vector<int> linex, liney;
    func(x, linex);
    func(y, liney);
    int currx = 0, curry = 0, ans = 0;
    while (currx < linex.size() && curry < liney.size() && linex[currx] != liney[curry]) {
        if (linex[currx] > liney[curry])
            currx++;
        else
            curry++;
        ans++;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", solve(x, y));
    }
    return 0;
}