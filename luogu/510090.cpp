#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		long long int a, b;
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		if(a == 0 || b == 0 || a * b < 0) 
			cout << 0 << endl;
		else 
			cout << min(abs(a), min(abs(b), abs(b-a))) << endl;
	}
	return 0;
}
