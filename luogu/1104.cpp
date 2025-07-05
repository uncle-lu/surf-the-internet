#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	int y, m, d, sit;
	string str;
	friend bool operator<(const node a, const node b) {
		return a.y < b.y 
			|| (a.y == b.y && a.m < b.m) 
			|| (a.y == b.y && a.m == b.m && a.d < b.d)
			|| (a.y == b.y && a.m == b.m && a.d == b.d && a.sit > b.sit);
	}
};
node line[110];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> line[i].str >> line[i].y >> line[i].m >> line[i].d;
		line[i].sit = i;
	}
	sort(line, line+n);
	for(int i = 0; i < n; i++) 
		cout << line[i].str << '\n';
	return 0;
}
