//���⣺�������������Ż��߾���ȡ�ࣩ 
#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
long long ksc(long long a,long long b,long long c)  //�߾�����(a*b)%c 
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
