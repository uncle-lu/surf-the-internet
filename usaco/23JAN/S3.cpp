#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int line[n];
	for (int i = 0; i < n; ++i) 
		cin >> line[i];

	int x = 0;
	while(true)
	{
		while(x < n && line[x]){
			cout << 'R';
			line[x]--;
			x++;
		}
		x--;
		
		while(x >= 0 && line[x] == 1){
			cout << 'L';
			line[x]--;
			x--;
		}
		if(x == -1)break;
		while(x >= 0 && line[x] != 1){
			cout << 'L';
			line[x]--;
			x--;
		}
		x++;
	}

	return 0;
}
