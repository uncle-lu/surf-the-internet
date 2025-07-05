#include <algorithm>
#include <cstdio>
using namespace std;

int s(int x) {
    int ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int mx = max(s(a), s(b));
    printf("%d", mx);
}