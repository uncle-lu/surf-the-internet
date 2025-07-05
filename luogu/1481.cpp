#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 2010;
string line[N];
int f[N];

int main() {
    int n, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> line[i];
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (line[i].find(line[j], 0) == 0)
                f[i] = max(f[i], f[j] + 1);
        mx = max(mx, f[i]);
    }
    cout << mx;
    return 0;
}