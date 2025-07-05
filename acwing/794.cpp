#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int number[N], res[N];

int main() {
    string str1;
    int x, m = 0;
    cin >> str1 >> x;
    int len1 = str1.size();
    for (int i = 0; i < len1; i++)
        number[i] = str1[len1 - 1 - i] - '0';
    for (int i = len1 - 1; i >= 0; i--) {
        m = m * 10 + number[i];
        res[i] = m / x;
        m %= x;
    }
    while (len1 > 1 && res[len1 - 1] == 0)
        len1--;
    for (int i = len1 - 1; i >= 0; i--)
        cout << res[i];
    cout << "\n" << m;
    return 0;
}