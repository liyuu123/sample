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
double a[105][105];

int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<n;i++){
		if(!a[i][i]){
			for(int j=i+1;j<=n;j++){
				if(a[j][i]){
					swap(a[i],a[j]);
					break;
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			double d=a[j][i]/a[i][i];
			for(int k=1;k<=n+1;k++){
				a[j][k]-=a[i][k]*d;
			}
		}
	}
	for(int i=n;i>=1;i--){
		a[i][i]=a[i][n+1]/a[i][i];
		for(int j=i-1;j>=1;j--){
			a[j][n+1]-=a[j][i]*a[i][i];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<floor(a[i][i]+0.5)<<" ";
	}
}
