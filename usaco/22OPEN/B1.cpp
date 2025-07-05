#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, cnt=0;
	cin >> n;
	vector<char>line(n);
	vector<bool>s;
	for(char& i : line)
		cin >> i;
	for (int i = 0; i < n; i=i+2) 
		if(line[i] != line[i+1])
		{
			if(line[i] == 'G')
				s.push_back(true);
			else
				s.push_back(false);
		}
	s.push_back(false);
	for (int i = 0; i < (int)s.size()-1; ++i) {
		if(s[i] ^ s[i+1])
			cnt++;
	}
	cout << cnt;

	return 0;
}
