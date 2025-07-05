#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int T;
	string str[10010];
	cin >> T;
	for(int i=1; i<=T; i++) {
		cin >> str[i];
		sort(str[i].begin(), str[i].end());
	}
	sort(str+1, str+1+T);
	int ans = T;
	for(int i=1; i<T; i++) {
		if(str[i] == str[i+1])
			ans--;
	}
	cout << ans;
	return 0;
}
