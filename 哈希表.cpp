#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m,ans=0;
int hash[10000010];
int pos(int x){
	int t=x%10000007;
	while(hash[t]&&hash[t]!=x)t++;
	return t;
}

int main()
{
	int x;
	n=read();
	for(int i=1;i<=n;i++){
		x=read();
		hash[pos(x)]=x;
	}
	m=read();
	for(int i=1;i<=m;i++){
		x=read();
		if(hash[pos(x)]!=x)ans++;
	}
	cout<<ans;
}
