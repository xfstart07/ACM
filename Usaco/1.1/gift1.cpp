/*
ID: xfstart2
LANG: C++
PROG: gift1
 */
#include<iostream>
#include<cstdio>
using namespace std;

int N;
int mo[11];
string na[11];
int Find(string s)
{
	int i;
	for(i=0;i<N;++i)
		if(s==na[i])
			return i;
}
int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int i,j,m,k,ai;
	string a,b;
	cin>>N;
	for(i=0;i<N;++i)
		cin>>na[i],mo[i]=0;
	for(i=0;i<N;++i)
	{
		cin>>a>>m>>k;
		ai=Find(a);
		int f=0;
		if(m) f=m/k;
		for(j=0;j<k;++j)
		{
			cin>>b;
			mo[Find(b)]+=f;
			mo[ai]-=f;
		}
	}
	for(i=0;i<N;++i)
		cout<<na[i]<<" "<<mo[i]<<endl; 
	return 0;
}