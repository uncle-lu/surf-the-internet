#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
bool vis[N];

int main() {
    int a, n, x;
    cin >> a >> n;
    vector<int> line;
    for (int i = a; i <= N; i++)
        if ((int)sqrt(i) * (int)sqrt(i) == i)
            for (int t = 1; i * t <= N && !vis[i * t]; t++) {
                vis[i * t] = true;
                line.push_back(i * t);
            }
    sort(line.begin(), line.end());
    for (int i = 1; i <= n; i++) {
        cin >> x;
        int l = 0, r = line.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (line[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (line[l] == x)
            cout << "lucky" << endl;
        else
            cout << line[l] << endl;
    }
    return 0;
}