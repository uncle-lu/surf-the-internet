#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool F[30][30];

int main()
{
	string s, t;
	cin >> s >> t;

	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < 18; ++j) {
			char x = i + 'a', y = j + 'a';
			string temp_1, temp_2;
			for(auto c : s)
				if(c == x || c == y)
					temp_1 += c;
			for(auto c : t)
				if(c == x || c == y)
					temp_2 += c;

			if(temp_1 != temp_2)
				F[i][j] = false;
			else
				F[i][j] = true;
		}
	}

	int k;
	cin >> k;
	while(k--){
		string temp;
		cin >> temp;
		bool flag = true;
		for(auto i : temp)
			for(auto j : temp)
			{
				if(!F[i-'a'][j-'a'])
					flag = false;
			}
		if(flag)
			cout << "Y";
		else
			cout << "N";
	}

	return 0;
}
