#include <iostream>
#include <string>
using namespace std;

const int N = 2010;
int num1[N], num2[N], res[2 * N];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.size(), len2 = str2.size(), len = len1 + len2;
    for (int i = 0; i < len1; i++)
        num1[i] = str1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; i++)
        num2[i] = str2[len2 - 1 - i] - '0';
    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            res[i + j] += num1[i] * num2[j];
    for (int i = 0; i < len; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    while (len > 1 && res[len - 1] == 0)
        len--;
    for (int i = len - 1; i >= 0; i--)
        cout << res[i];
    return 0;
}