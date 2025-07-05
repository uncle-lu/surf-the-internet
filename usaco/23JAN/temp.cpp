#include<iostream>
#include<string>
#include<set>
using namespace std;

set<pair<char, char> >s;

int main()
{
	string a, b;
	cin >> a >> b;
	int len = a.length();
	for (int i = 0; i < len; ++i) {
		s.insert(make_pair(a[i], b[i]));
	}
	for(auto i : s)
		cout << i.first << ' ' << i.second << endl;

	return 0;
}
