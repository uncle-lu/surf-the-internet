#include<iostream>
using namespace std;

int a[4], b[4], c[4];

bool check(int a_win, int b_win)
{
	int c_win=0;
	int temp_1 = 0, temp_2 = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			if(a[i] == c[j]) continue;
			if(a[i] < c[j]) 
				temp_1++;
			else 
				temp_2++;
		}
	if(temp_1 > temp_2)
		c_win++;
	else if(temp_1 < temp_2)
		a_win++;
	else
		return false;

	temp_1 = 0; temp_2 = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			if(b[i] == c[j]) continue;
			if(b[i] < c[j]) 
				temp_1++;
			else 
				temp_2++;
		}
	if(temp_1 > temp_2)
		c_win++;
	else if(temp_1 < temp_2)
		b_win++;
	else
		return false;

	if(a_win == 1 && b_win == 1 && c_win == 1)
		return true;
	
	return false;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		bool flag = false;
		for (int i = 0; i < 4; ++i)
			cin >> a[i];
		for (int i = 0; i < 4; ++i)
			cin >> b[i];

		int a_temp = 0, b_temp = 0, _a_win = 0, _b_win = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				if(a[i] == b[j]) continue;
				if(a[i] < b[j]) 
					b_temp++;
				else 
					a_temp++;
			}
		if(a_temp > b_temp)
			_a_win++;
		else if(a_temp < b_temp)
			_b_win++;
		else{
			cout << "no" << endl;
			continue;
		}

		for (c[1] = 1; c[1] <= 10 && !flag; ++c[1])
			for (c[2] = c[1]; c[2] <= 10 && !flag; ++c[2])
				for (c[3] = c[2]; c[3] <= 10 && !flag; ++c[3])
					for (c[0] = c[3]; c[0] <= 10 && !flag; ++c[0]) {
						if(check(_a_win, _b_win))
							flag = true;
					}
		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
