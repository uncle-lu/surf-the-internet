#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int N = 510;
int num1[N], num2[N], res[N];

int main() {
    string str1, str2; // 两个字符串
    cin >> str1 >> str2;
    int len1 = str1.size(), len2 = str2.size(), len; // 测量长度
    for (int i = 0; i < len1; i++)
        num1[i] = str1[len1 - 1 - i] - '0'; // 倒置并且转换为整数
    for (int i = 0; i < len2; i++)
        num2[i] = str2[len2 - 1 - i] - '0';
    len = max(len1, len2);
    for (int i = 0; i < len; i++) // 两数按位相加
        res[i] = num1[i] + num2[i];
    for (int i = 0; i < len; i++) { // 两数从低位开始进位
        res[i + 1] += res[i] / 10;  // 第i位超过10的部分向前进位
        res[i] %= 10;               // 第i位留下小于10的部分
    }
    if(res[len] != 0) {
        len++;
    }
    for(int i = len-1; i>=0; i--)
        cout << res[i];
    return 0;
}