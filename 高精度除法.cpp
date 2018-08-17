#include<bits/stdc++.h>
using namespace std;
int a[205],b,c[205];
int n;
char s[205];

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++){
		a[i]=s[i]-'0';
	}
	scanf("%d",&b);
	int x=0;
	for(int i=0;i<n;i++){
		c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	int i=0;
	while(!c[i]&&i<n-1)i++;
	for(;i<n;i++){
		cout<<c[i];
	}cout<<endl;
	cout<<x;						//ำเสý 
}
