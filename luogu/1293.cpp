#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct node {
    int p, dis;
    string name;
};
node line[150];

int main() {
    int n = 0;
    while (true) {
        n++;
        cin >> line[n].p >> line[n].dis >> line[n].name;
        if (line[n].dis == 0)
            break;
    }
    int mi = 2147483647, d = 0;
    string ans;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int t = 1; t <= n; t++) {
            temp += abs(line[i].dis - line[t].dis) * (line[t].p);
        }
        if ((mi == temp && d > line[i].dis) || (mi > temp)) {
            mi = temp;
            ans = line[i].name;
            d = line[i].dis;
        }
    }
    cout << ans << " " << mi;
    return 0;
}