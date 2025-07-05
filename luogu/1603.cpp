#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string mp[21]={
	" ","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"
};

int turn(string temp) {
	for(int i=1; i<=20; i++) 
		if(temp == mp[i])
			return i;
	if(temp == "a" || temp == "another" || temp == "first")
		return 1;
	if(temp == "both" || temp == "second")
		return 2;
	if(temp == "third")
		return 3;
	return -1;
}

bool cmp(string a, string b){
	return a.length() < b.length() || (a.length()==b.length() && a < b);
}

int main() {
	string str[10], line[10];
	int cnt = 0;
	for(int i=1; i<=6; i++) {
		cin >> line[i];
		int temp = turn(line[i]);
		if(temp == -1)continue;
		temp = temp * temp % 100;
		if(temp == 0)continue;
		line[cnt++] = to_string(temp);
	}
	sort(line, line+cnt, cmp);
	for(int i=0; i<cnt; i++){
		if(line[i].length() == 1 && i != 0)
			cout << "0";
		cout << line[i];
	}
	if(cnt == 0)
		cout << "0";
	return 0;
}
