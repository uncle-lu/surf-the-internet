#include <algorithm>
#include <iostream>
#include <string>

using ull = unsigned long long int;
const int N = 1e4 + 10;
const ull p = 998244353;
ull H[N];

ull hash_str(std::string str) {
    ull sum = 0;
    for (char c : str)
        sum = sum * p + c;
    return sum;
}

int main() {
    int n;
    std::string str;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> str;
        H[i] = hash_str(str);
    }
    std::sort(H + 1, H + 1 + n);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (H[i] != H[i - 1])
            ans++;
    std::cout << ans;
    return 0;
}