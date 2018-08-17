//例题：病毒（快速幂优化高精度取余） 
#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
long long ksc(long long a,long long b,long long c)  //高精度求(a*b)%c 
{
	long long i=0;
	while(b){
		if(b&1)i=(i+a)%c;
		b/=2;
		a=(a+a)%c;
	}
	return i;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c;
	cout<<ksc(a,b,c);
}
