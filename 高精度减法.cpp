#include<bits/stdc++.h>
using namespace std;
char s[205],t[205];
int n,m,f=1,len,tot,x;
int a[205],b[205],c[205];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)a[n-i]=s[i]-'0';
	scanf("%s",t);
	m=strlen(t);
	for(int i=0;i<m;i++)b[m-i]=t[i]-'0';
	
	if(n<m||(strcmp(s,t)<0&&n==m))f=-1;
	tot=max(n,m);
	if(f==1)
	{
		for(int i=1;i<=tot;i++)
		{
			c[i]=(a[i]+x+10-b[i])%10;
			if(a[i]+x<b[i])x=-1;else x=0;
		}
	}
	if(f==-1)
	{
		for(int i=1;i<=tot;i++)
		{
			c[i]=(b[i]+x+10-a[i])%10;
			if(b[i]+x<a[i])x=-1;else x=0;
		}
	}
	while(c[tot]==0)tot--;
	if(f==-1)cout<<'-';
	for(int i=tot;i>=1;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
}
