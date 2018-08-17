#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n;
long long ans=0;
int a[100005],tmp[100005];
inline void merge(int l,int mid,int r){
	int k=l,i=l;
	int j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			tmp[k++]=a[i++];
		}
		else {
			tmp[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid)tmp[k++]=a[i++];
	while(j<=r)tmp[k++]=a[j++];
	for(int i=l;i<=r;i++){
		a[i]=tmp[i];
	}
}
inline void mergesort(int l,int r){
	if(l<r){
		int mid=l+r>>1;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	mergesort(1,n);
	cout<<ans;
}
