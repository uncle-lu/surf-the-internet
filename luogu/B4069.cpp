#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a[n], s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            s = s + a[i];
        bool flag = true;
        for (int i = 0; i < s.length() - 1; i++)
            if (s[i] > s[i + 1]) {
                flag = false;
                break;
            }
        cout << (flag ? 1 : 0) << endl;
    }
    return 0;
}