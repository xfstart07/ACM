/*
ID: xfstart2
LANG: C++
PROG: namenum
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ys[26]={'2','2','2','3','3','3','4','4','4',
	                '5','5','5','6','6','6','7','1','7',
	                '7','8','8','8','9','9','9','1',};
bool check(char *s,char *ch)
{
	int i,l=strlen(s);
	for(i=0;i<l;++i)
		if(s[i] != ys[ch[i]-'A'])
			return 0;
	return 1;
}
int main()
{
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	
	char s[15],ch[15];
	scanf("%s",s);
	
	freopen("dict.txt","r",stdin);
	
	bool flg=1;
	while(scanf("%s",ch)!=EOF)
	{
		if(strlen(s)==strlen(ch) && check(s,ch))
		{
			printf("%s\n",ch);
			flg=0;
		}
	}
	if(flg)
		printf("NONE\n");
	return 0;
}