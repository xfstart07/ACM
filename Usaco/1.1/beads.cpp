/*
ID: xfstart2
LANG: C++
PROG: beads
 */
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int N,res;
string s;
int rh[710],bh[710],rt[710],bt[710];
inline int max(int a,int b)
{ return a>b?a:b; }
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int i;
	cin>>N>>s;
	s+=s; N*=2;
	
	rh[0]=bh[0]=0;
	for(i=1;i<=N;++i)
		switch(s[i-1]){
			case 'w' :
				rh[i]=rh[i-1]+1;
				bh[i]=bh[i-1]+1;
				break;
			case 'r' :
				rh[i]=rh[i-1]+1;
				bh[i]=0;
				break;
			case 'b' :
				rh[i]=0;
				bh[i]=bh[i-1]+1;
				break;
		}
	rt[N+1]=bt[N+1]=0;
	for(i=N;i>0;--i)
		switch(s[i-1]){
			case 'w' :
				rt[i]=rt[i+1]+1;
				bt[i]=bt[i+1]+1;
				break;
			case 'r' :
				rt[i]=rt[i+1]+1;
				bt[i]=0;
				break;
			case 'b' :
				rt[i]=0;
				bt[i]=bt[i+1]+1;
				break;
		}
	res=0;
	for(i=1;i<=N;++i)
		res=max(res,max(rh[i],bh[i])+max(bt[i+1],rt[i+1]));
	cout<<(res>N/2?N/2:res)<<endl;
	return 0;
}
