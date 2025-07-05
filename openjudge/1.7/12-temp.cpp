#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char str1[60],str2[60],str3[60],str4[60];
	int len;
	scanf("%s",str1);
	len=strlen(str1); 
	for(int i=0;i<len;i++){
		if(str1[i]>='a'&&str1[i]<='z'){
			str2[i]=str1[i]-32; 
		}
		else if(str1[i]>='A'&&str1[i]<='Z'){
			str2[i]=str1[i]+32;
		}
	}
	for(int i=0;i<len;i++){
		str3[i]=str2[len-i-1];
	}
	for(int i=0;i<len;i++){
		if((str3[i]>='x'&&str3[i]<='z')||(str3[i]>='X'&&str3[i]<='Z')){
			str4[i]=str3[i]-23;
		}
		else if((str3[i]>='a'&&str3[i]<='w')||(str3[i]>='A'&&str3[i]<='W')){
			str4[i]=str3[i]+3;
		}
	}
	for(int i=0;i<len;i++){
		printf("%c",str4[i]);
	}
	return 0;
}
