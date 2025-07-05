#include<iostream>
using namespace std;

bool x_win_y(int x[4], int y[4])
{
	int x_cnt = 0, y_cnt = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if(x[i] < y[j])y_cnt++;
			else if(x[i] > y[j])x_cnt++;
		}
	}
	return x_cnt > y_cnt;
}

int main()
{
	int a[4], b[4], c[4], T;
	cin >> T;
	while(T--)
	{
		for (int i = 0; i < 4; ++i)
			cin >> a[i];
		for (int i = 0; i < 4; ++i)
			cin >> b[i];

		bool flag = false;
		for (c[0] = 1; c[0] <= 10 && !flag; ++c[0])
			for (c[1] = c[0]; c[1] <= 10 && !flag; ++c[1])
				for (c[2] = c[1]; c[2] <= 10 && !flag; ++c[2])
					for (c[3] = c[2]; c[3] <= 10 && !flag; ++c[3]) {
						if(x_win_y(a, b) && x_win_y(b, c) && x_win_y(c, a))
							flag = true;
						else if(x_win_y(a, c) && x_win_y(c, b) && x_win_y(b, a))
							flag = true;
					}

		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
