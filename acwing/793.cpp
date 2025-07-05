#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 110010;
int number1[N], number2[N], res[N];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int len1 = str1.size(), len2 = str2.size(), len = len1 + len2;
    for (int i = 0; i < len1; i++)
        number1[i] = str1[i] - '0';
    for (int i = 0; i < len2; i++)
        number2[i] = str2[i] - '0';
    for (int i = 0; i < len1; i++) // 模拟竖式，将第i位与第j位相乘，存储在i+j位（位权叠加）
        for (int j = 0; j < len2; j++)
            res[i + j] += number1[i] * number2[j];
    for (int i = 0; i < len; i++) { // 处理进位
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    while (len - 1 > 0 && res[len - 1] == 0) // 去除前导零
        len--;
    for (int i = len - 1; i >= 0; i--)
        cout << res[i];
    return 0;
}