#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m;
int gcd(int m,int n){
	if(m<n)swap(m,n);
	while(n)
	{
		int c=m%n;
		m=n;n=c;
	}
	return m;
}
int lcm(int m,int n,int g)
{
	int tmp=m*n;
	tmp/=g;
	return tmp;
}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	m=read();n=read();
	int g=gcd(m,n);
	cout<<g<<endl;
	cout<<lcm(m,n,g);
}
