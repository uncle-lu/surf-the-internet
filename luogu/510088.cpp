#include<iostream>
using namespace std;

int main() {
	int n;
	unsigned long long sum = 1;
	cin >> n;
	for(int i = 1; i <= n; i++)
		sum *= i;
	if(sum % (n+1) == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
