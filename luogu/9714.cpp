#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int t[n + 10], b[n + 10];
        for (int i = 1; i <= n; i++)
            cin >> t[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        bool flag = false;
        // x * t[i] + y * (t[i] + t[n-i+1]) == b[i]
        for (int x = 0; x <= b[1] / t[1]; x++) { // 枚举x
            int y;
            if ((b[1] - x * t[1]) % (t[1] + t[n]) == 0) // 判断 y 是否存在
                y = (b[1] - x * t[1]) / (t[1] + t[n]);  // 计算y
            else
                continue;   // 当前的x错误
            bool ok = true; // 检查 t[2] ~ t[n] 是否 x, y 符合条件
            for (int i = 2; i <= n && ok; i++)
                if (x * t[i] + y * (t[i] + t[n - i + 1]) != b[i])
                    ok = false;
            if (ok) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}