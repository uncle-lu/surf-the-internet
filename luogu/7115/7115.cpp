#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][408],t[55],ans=0,am[8200005][2];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)t[i]=m;
	for(int c=1;c<n;c++){
		int f=n+2-c;
		for(int i=1;i<=n+1-c;i++){
			int temp=0,nxt=i+1;
			for(int j=1;j<=m;j++)
				if(a[i][j]==c)temp++;
			if(nxt==f)nxt=i-1;
			for(int j=1;j<=temp;j++){
				am[++ans][0]=nxt;
				am[ans][1]=f;
			}
			for(int j=m;j>=1;j--){
				if(a[i][j]==c){
					am[++ans][0]=i;
					am[ans][1]=nxt;
				}else{
					am[++ans][0]=i;
					am[ans][1]=f;
				}
			}
			for(int j=1;j<=m-temp;j++){
				am[++ans][0]=f;
				am[ans][1]=i;
			}
			for(int j=1;j<=temp;j++){
				am[++ans][0]=nxt;
				am[ans][1]=i;
			}
			for(int j=1;j<=temp;j++){
				am[++ans][0]=f;
				am[ans][1]=nxt;
			}
			for(int j=1;j<=m-temp;j++){
				while(a[i][j]==c){
					for(int k=j;k<m;k++){
						swap(a[i][k],a[i][k+1]);
					}
				}
			}
		}
		for(int i=1;i<f;i++){
			while(a[i][t[i]]==c){
				am[++ans][0]=i;
				am[ans][1]=f;
				t[i]--;
			}
		}
		for(int i=1;i<f-1;i++){
			while(t[i]<m){
				am[++ans][0]=f-1;
				am[ans][1]=i;
				a[i][++t[i]]=a[f-1][t[f-1]--];
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++){
		cout<<am[i][0]<<' '<<am[i][1]<<endl;
	}
	return 0;
}
