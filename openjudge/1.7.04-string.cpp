#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a >> b;
		if((a == "Rock" && b == "Scissors") ||
				(a == "Scissors" && b == "Paper") ||
				(a == "Paper" && b == "Rock"))
			cout << "Player1" << endl;
		else if(a == b)
			cout << "Tie" << endl;
		else
			cout << "Player2" << endl;
	}

	return 0;
}
