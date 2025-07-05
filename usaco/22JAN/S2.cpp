#include<iostream>
#include<stack>
using namespace std;

int main()
{
	long long int n, temp, ans = 0;
	cin >> n;
	stack<pair<int, long long int> >s;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		while((!s.empty()) && s.top().second <= temp)
		{
			ans += i - s.top().first + 1;
			s.pop();
		}
		if(!s.empty())
			ans += i - s.top().first + 1;
		s.push(make_pair(i, temp));
	}
	cout << ans;
	return 0;
}
