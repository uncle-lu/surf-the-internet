#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, mx = 0, temp, cnt0 = 0;
	cin >> n;
	for(int i = 1; i<=n; i++) {
		cin >> temp;
		if(temp == 0)
			cnt0++;
		else 
			mx = max(mx, temp);
	}
	if(cnt0>mx) 
		n -= (cnt0-mx);
	cout << n;
	return 0;
}
