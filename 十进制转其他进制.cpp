#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m,t=0;
int a[55];
inline void check(int x){
	if(x<10)cout<<x;
	else{
		putchar(x+55);
	}
}

int main()
{
	n=read();
	m=read();
	while(n){
		a[++t]=n%m;
		n=n/m;
	}
	while(a[t]==0)t--;
	for(int i=t;i>=1;i--)check(a[i]);
}
