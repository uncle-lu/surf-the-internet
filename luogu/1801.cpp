#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> >small;
priority_queue<int, vector<int>, less<int> >big;

int main()
{
	int m, n, temp;
	cin >> m >> n;
	vector<int>line(m);
	for(int& i:line)cin >> i;
	int sit = 0;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		while(sit <= temp-1)
		{
			if((!big.empty()) && line[sit] < big.top())
			{
				small.push(big.top());
				big.pop();
				big.push(line[sit]);
			}
			else
				small.push(line[sit]);
			sit++;
		}

		big.push(small.top());
		small.pop();
		cout << big.top() << endl;
	}

	return 0;
}
