#include<bits/stdc++.h>
#define ll long long
#define m(a) memset(a,0,sizeof(a))
#define FE ""
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}

int main(){
	freopen(FE".in","r",stdin);
	freopen(FE".out","w",stdout);
}
