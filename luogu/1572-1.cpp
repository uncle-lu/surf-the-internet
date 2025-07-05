#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		long long int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main() {
	string str;
	cin >> str;
	stringstream s(str);
	long long int c, d, a = 0, b = 1, temp; 
	char type;
	while(s >> c >> type >> d) {
		c *= b; a *= d; b *= d;
		a += c;
		temp = gcd(abs(a), abs(b));
		a /= temp; b/= temp;
	}
	if(b == 1)
		cout << a;
	else
		cout << a << "/" << b;
	return 0;
}
