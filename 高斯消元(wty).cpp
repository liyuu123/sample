#include<bits/stdc++.h>
using namespace std;
double a[105][105];
int n;
int main(){
//����	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	  	for(int j=1;j<=n+1;++j)
			scanf("%lf",&a[i][j]);
//�����С���Ԫ 
	for(int i=1;i<=n-1;++i){
		if(!a[i][i])
			for(int j=i+1;j<=n;++j)
		   		if(a[j][i]){
				   swap(a[i],a[j]);
				   break;
				}    
		for(int j=i+1;j<=n;++j){
			double b=a[j][i]/a[i][i];
		  	for(int k=i;k<=n+1;++k) a[j][k]-=a[i][k]*b;
		}
	}
//�ش� 
	for(int i=n;i>=1;--i){
		a[i][i]=a[i][n+1]/a[i][i];
		for(int j=1;j<i;++j) a[j][n+1]-=a[j][i]*a[i][i];
	} 
//��� (��������)
	for(int i=1;i<=n;++i) cout<<floor(a[i][i]+0.5)<<" ";
}
