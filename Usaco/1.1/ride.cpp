/*
ID: xfstart2	
LANG: C++
PROG: ride
 */
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string a,b;
	int i,aa,bb;
	
	cin>>a>>b;
	
	for(aa=1,i=0;i<a.size();++i)
		aa*=a[i]-64;
	for(bb=1,i=0;i<b.size();++i)
		bb*=b[i]-64;
	
	if((aa%47) == (bb%47))
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
	return 0;
}