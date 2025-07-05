#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int m[N];

int main() {
    int n, b, cnt = 0;
    cin >> n >> b;
    for (int i = 2; i <= n; i++)
        if (m[i] == 0) {
            m[i] = i;
            for (int j = 1; j * i <= n; j++)
                m[j * i] = i;
        }

    for (int i = 1; i <= n; i++)
        if (m[i] <= b)
            cnt++;
    cout << cnt;
    return 0;
}