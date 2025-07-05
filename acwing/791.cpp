#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
string str1, str2;
int number1[N], number2[N];

int main() {
    cin >> str1; // 以字符串形式，读入第一行数
    cin >> str2; // 以字符串形式，读入第二行数
    int len1 = str1.size(), len2 = str2.size();
    reverse(str1.begin(), str1.end()); // 将字符串倒置
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < len1; i++) // 将字符转换为数值
        number1[i] = str1[i] - '0';
    for (int i = 0; i < len2; i++)
        number2[i] = str2[i] - '0';
    int len = max(len1, len2);    // 选择出最长的长度
    for (int i = 0; i < len; i++) // 两数相加
        number1[i] += number2[i];
    for (int i = 0; i < len; i++) { // 处理进位
        number1[i + 1] += number1[i] / 10;
        number1[i] %= 10;
    }
    while (number1[len] > 0) // 当高位出现进位时，增大长度
        len++;
    for (int i = len - 1; i >= 0; i--)
        cout << number1[i];
    return 0;
}