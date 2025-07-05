#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, ans;
    cin >> n;
    vector<int> line(n);
    for (int i = 0; i < n; i++)
        cin >> line[i];
    sort(line.begin(), line.end(), cmp);
    n = min(n, 32);
    ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                ans = max(ans, line[i] & line[j]);
    cout << ans;
    return 0;
}