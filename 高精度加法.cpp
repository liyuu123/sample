#include<bits/stdc++.h>
using namespace std;
char s[205];
int n,m,len,tot,x;
int a[205],b[205],c[205];

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		a[n-i]=s[i]-'0';
	}
	scanf("%s",s);
	m=strlen(s);
	for(int i=0;i<m;i++)
	{
		b[n-i]=s[i]-'0';
	}
	tot=max(n,m);
	for(int i=1;i<=tot;++i)
	{
		c[i]=(a[i]+b[i]+x)%10;
		x=(a[i]+b[i]+x)/10;
	}
	if(x)
	{
		tot++;c[tot]=x;
	}
	while(c[tot]==0)tot--; 
	for(int i=tot;i>=1;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
}
