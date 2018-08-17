#include<bits/stdc++.h>
using namespace std;
char s[12];
int tot=0;
struct node{
	int son[26];
	int num;
}trie[1000005];
inline void build_trie(char s[12])
{
	int pos=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(!trie[pos].son[s[i]-'a'])
		{
			trie[pos].son[s[i]-'a']=++tot;
		}
		pos=trie[pos].son[s[i]-'a'];
		trie[pos].num++;
	}
}
inline void fin_d(char s[12])
{
	int pos=0;bool sig=1;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(!trie[pos].son[s[i]-'a']){
			cout<<0<<endl;sig=0;break;
		}
		pos=trie[pos].son[s[i]-'a'];
	}
	if(sig)cout<<trie[pos].num<<endl;
}

int main()
{
	gets(s);
	while(s[0]!='\0')
	{
		build_trie(s);
		gets(s);
	}
	while(gets(s))
	{
		fin_d(s);
	}
}
