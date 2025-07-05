#include <iostream>
using namespace std;

int main() {
    bool flag = false; // 控制乘号的出现
    long long x, temp;
    cin >> x;
    for (long long int p = 2; p * p <= x; p++) {
        if (x % p != 0)
            continue;
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        if (flag)
            cout << " * ";
        cout << p;
        if (cnt > 1)
            cout << "^" << cnt;
        flag = true;
    }
    if (x != 0) {
        if (flag)
            cout << " * ";
        cout << x;
    }
    return 0;
}