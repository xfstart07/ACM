/*
ID: xfstart2
LANG: C++
PROG: palsquare
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char num[21]={'0','1','2','3','4','5','6','7',
	                    '8','9','A','B','C','D','E','F','G','H','I','J','K',};
bool equal(string s)
{
	int i,l=s.size();
	for(i=0;i<l/2;++i)
		if(s[i] != s[l-i-1])
			return 0;
	return 1;
}
void check(int b,int k)
{
	string s="";
	int a=k*k;
	while(a)
	{
		s=num[a%b]+s;
		a/=b;
	}
	if(equal(s))
	{
		string cc="";
		while(k)
		{
			cc=num[k%b]+cc;
			k/=b;
		}
		cout<<cc<<" "<<s<<endl;
	}
}
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int B,i;
	cin>>B;
	for(i=1;i<=300;++i)
		check(B,i);
	return 0;
}