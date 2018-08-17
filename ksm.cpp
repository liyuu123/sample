#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c;
ll ksm(ll a,ll b,ll c){
	ll ans=1;
	a%=c;
	while(b){
		if(b&1)ans=(ans*a)%c;
		b>>=1;
		a=(a*a)%c;
	}
	if(a==0&&ans==1)ans--;
	return ans;
}
int main(){
	cin>>a>>b>>c;
	cout<<a<<"^"<<b<<" mod "<<c<<"="<<ksm(a,b,c)<<endl;
}
