/*
ID: xfstart2
LANG: C++
PROG: fact4
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	
	int N,i,S=1,k=0;
	
	cin>>N;
	
	for(i=2;i<=N;++i)
	{
		S*=i;
		while(S%5 == 0) S/=5,++k;
		while(S%2 == 0 && k)
			S/=2,--k;
		S%=100;
	}
	S%=10;
	cout<<S<<endl;
	return 0;
}