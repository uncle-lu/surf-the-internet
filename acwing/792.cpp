#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;
int number1[N], number2[N], res[N]; // res[]结果数组

int main() {
    bool flag = false; // 是否为负数
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() < str2.size() ||
        (str1.size() == str2.size() && str1 < str2)) { // 当被减数小时为负数
        flag = true;
        swap(str1, str2);
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int len1 = str1.size(), len2 = str2.size();
    for (int i = 0; i < len1; i++)
        number1[i] = str1[i] - '0';
    for (int i = 0; i < len2; i++)
        number2[i] = str2[i] - '0';
    for (int i = 0; i < len1; i++) {
        res[i] += number1[i] - number2[i]; // 计算第i位
        if (res[i] < 0) {                  // 为负数时，向高位借位
            res[i + 1]--;
            res[i] += 10;
        }
    }
    while (len1 - 1 > 0 && res[len1 - 1] == 0) // 减去前导0
        len1--;
    if (flag) // 结果为负数时，输出符号
        cout << "-";
    for (int i = len1 - 1; i >= 0; i--)
        cout << res[i];
    return 0;
}