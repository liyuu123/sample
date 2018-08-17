#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n;
int a[10005];
int num=0;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		int l=0,r=num,mid;
		while(l<=r){
			mid=l+r>>1;
			if(k<=a[mid])r=mid-1;
			else l=mid+1;
		}
		if(l>num){
			num++;
		}a[l]=k;
	}
	cout<<num;
}
