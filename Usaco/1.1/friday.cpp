/*
ID: xfstart2
LANG: C++
PROG: friday
 */
#include<iostream>
#include<cstdio>
using namespace std;

int N;
int day[7];
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int i,j,s;
	cin>>N;
	for(i=0;i<7;++i) day[i]=0;
	s=13;
	for(i=1900;i<1900+N;++i)
	{
		if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			m[2]=29;
		else
			m[2]=28;
		for(j=1;j<=12;++j)
			day[s%7]++,s+=m[j];
	}
	cout<<day[6];
	for(i=0;i<6;++i)
		cout<<" "<<day[i];
	cout<<endl;
	return 0;
}