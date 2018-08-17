#include<bits/stdc++.h> 
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
const int mod=10000;
int n;
struct node{
	int a[5][5];
};
node matrix_ksm(node a,node b){
	node c;
	memset(c.a,0,sizeof(c.a));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c.a[i][j]+=a.a[i][k]*b.a[k][j];
				if(c.a[i][j]>=mod){
					c.a[i][j]%=mod;
				}
			}
		}
	}
	return c;
}
void fib(){
	node x,t;
	x.a[0][0]=1;
	x.a[0][1]=1;
	x.a[1][0]=1;
	x.a[1][1]=0;
	t=x;
	n--;
	while(n){
		if(n&1)x=matrix_ksm(x,t);
		t=matrix_ksm(t,t);
		n>>=1;
	}
	cout<<x.a[0][1]<<endl;
}
int main()
{
	n=1;
	while(n!=-1){
		n=read();
		if(n==-1)break;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		fib();
	}
}
