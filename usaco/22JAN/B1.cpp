#include<iostream>
using namespace std;

int tong[30];
char maps[3][3], temp[3][3];

int main()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> maps[i][j];
			tong[ maps[i][j] - 'A' ] ++;
		}
	}
	int green = 0, yellow = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> temp[i][j];
			if(temp[i][j] == maps[i][j])
			{
				green ++;
				tong[temp[i][j]-'A']--;
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if(temp[i][j] != maps[i][j] && tong[temp[i][j] - 'A'])
			{
				yellow++;
				tong[temp[i][j] - 'A']--;
			}
		}
	}
	cout << green << endl << yellow;
	return 0;
}
