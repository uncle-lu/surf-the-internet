#include<iostream>
using namespace std;

int line[100010], s[100010], target[100010], top;

int main()
{
	int T, n;
	cin >> T;
	while(T--)
	{
		top = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> line[i];
		for (int i = 0; i < n; ++i)
			cin >> target[i];

		int iter = 0;
		for (int i = 0; i < n; ++i) {
			s[++top] = line[i];
			while(top > 0 && s[top] == target[iter])
			{
				iter++;
				top--;
			}
		}
		if(top == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
