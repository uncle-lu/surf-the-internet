#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using ull = unsigned long long;
const int N = 100;
const ull P = 1e9 + 7;
ull h1[N], h2[N], p[N];

int solve(std::string str1, std::string str2) {
    memset(h1, 0, sizeof(h1));
    memset(h2, 0, sizeof(h2));
    int len1 = str1.length(), len2 = str2.length(), ans = 0;
    h1[0] = str1[0] - 'a';
    for (int i = 1; i < len1; i++)
        h1[i] = h1[i - 1] * P + (str1[i] - 'a');
    h2[0] = str2[0] - 'a';
    for (int i = 1; i < len2; i++)
        h2[i] = h2[i - 1] * P + (str2[i] - 'a');

    int curr1 = 0, curr2 = len2 - 1;
    while (curr1 < len1 && curr2 >= 0) {
        if (h1[curr1] == (h2[len2 - 1] - h2[curr2 - 1] * p[curr1 + 1]))
            ans = curr1 + 1;
        curr1++;
        curr2--;
    }

    return ans;
}

int main() {
    int ans = 0;
    std::string str1, str2;
    p[0] = 1;
    for (int i = 1; i <= 81; i++)
        p[i] = p[i - 1] * P;
    std::cin >> str1 >> str2;
    ans = solve(str1, str2);
    ans = std::max(ans, solve(str2, str1));
    std::cout << ans;
    return 0;
}