#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	if((int)a.find(b) != -1)
		cout << b << " is substring of " << a ;
	else if((int)b.find(a) != -1)
		cout << a << " is substring of " << b ;
	else
		cout << "No substring";
	return 0;
}
