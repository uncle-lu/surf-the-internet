#include <iostream>
#include <iomanip>
using namespace std;
double   line [11],sum = 0;
int main(){ 
	int x;
	line[1]=28.9 ;
	line[2]= 32.7;
	line[4]= 45.6;
	line[5]= 78;
	line[6]= 35;
	line[6]= 86.2;
	line[7]= 27.8;
	line[8]=43;
	line[9]=56;
	line[10]=65;
	for (int i = 1;i <= 10;i++){
		cin >> x;
		sum = sum + x*line[i];
	}    
	cout << sum;
	return 0;
} 
