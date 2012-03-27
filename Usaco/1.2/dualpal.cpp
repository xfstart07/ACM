/*
ID: xfstart2
LANG: C++
PROG: dualpal
*/
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

char num[10]={'0','1','2','3','4','5','6','7','8','9'};

bool equal(string s)
{
	int i,l=s.size();
	for(i=0;i<l/2;++i)
		if(s[i] != s[l-i-1])
			return 0;
	return 1;
}

bool check(int n,int b)
{
	string s="";
	while(n)
	{
		s=num[n%b]+s;
		n/=b;
	}
	if(equal(s))
		return 1;
	return 0;
}
int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s,i,j,d;
	cin>>n>>s;
	
	for(i=s+1;n;++i)
	{
		for(j=2,d=0;j<=10&&d<2;++j)
			if(check(i,j)) d++;
		if(d>1)
			cout<<i<<endl,n--;
	}
	return 0;
}
