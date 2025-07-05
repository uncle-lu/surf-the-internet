#include<iostream>
using namespace std;
const int N=2e5+10;
int m,n,a[N],u[N],heap1[N],heap2[N],top1,top2,ge=1;
void insert1(int x){
	heap1[++top1]=x;
	int t=top1;
	while(heap1[t]>heap1[t/2]&&t>1){
		swap(heap1[t],heap1[t/2]);
		t/=2;
	}
	return ;
}
void insert2(int x){
	heap2[++top2]=x;
	int t=top2;
	while(heap2[t]<heap2[t/2]&&t>1){
		swap(heap2[t],heap2[t/2]);
		t/=2;
	}
	return ;
}
void del1(){
	swap(heap1[1],heap1[top1]);
	top1--;
	int t=1,son=2;
	while(t<=top1&&son<=top1){
		if(heap1[son+1]>heap1[son]&&son<top1)son++;
		if(heap1[t]<heap1[son]){
			swap(heap1[t],heap1[son]);
			t=son;
			son=t*2;
		}else{
			break;
		}
	}
	return ;
}
void del2(){
	swap(heap2[1],heap2[top2]);
	top2--;
	int t=1,son=2;
	while(t<=top2&&son<=top2){
		if(heap2[son+1]<heap2[son]&&son<top2)son++;
		if(heap2[t]>heap2[son]){
			swap(heap2[t],heap2[son]);
			t=son;
			son=t*2;
		}else{
			break;
		}
	}
	return ;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>u[i];
	}
	for(int i=1;i<=m;i++){
		if(top1 >= 1 && a[i]<heap1[1]){
			insert2(heap1[1]);
			del1();
			insert1(a[i]);
		}else{
			insert2(a[i]);
		}
		while(u[ge]==i){
			cout<<heap2[1]<<endl;
			ge++;
			insert1(heap2[1]);
			del2();
		}
	}
	return 0;
}
