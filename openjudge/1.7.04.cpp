#include<bits/stdc++.h> 
using namespace std;
int main(){
	char str1[10],str2[10];
	int n;
	scanf("%d",&n);
	for(int i = 0;i<=n;++i){
		scanf("%s %s",str1,str2);
		if((str1[0] == 'R'&&str2[0] == 'S')||(str1[0] == 'S'&&str2[0] == 'P')||(str1[0] == 'P'&&str2[0] == 'R')){
			printf("Player1\n");
		}
		else if((str2[0] == 'R'&&str1[0] == 'S')||(str2[0] == 'S'&&str1[0] == 'P')||(str2[0] == 'P'&&str1[0] == 'R')){
			printf("Player2\n");
		}
		else{
			printf("Tie\n");
		}
	}
	return 0;
}
