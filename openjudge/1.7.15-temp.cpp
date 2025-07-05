#include<iostream>
#include<cstring>
using namespace std;
char str[110];
int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		scanf("%s", str);
		int len = strlen(str);
		if(str[0]>='a'&&str[0]<='z'){
			str[0]=str[0]-'a'+'A';
		}
		for(int j = 1;j<len;j++){
			if(str[j]>='A'&&str[j]<='Z')
				str[j] = str[j]-'A'+'a';
		}
		cout<<str<<endl;
	}
	return 0;
}
