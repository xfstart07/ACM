/*
ID: xfstart2
LANG: C++
PROG: ratios
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long Llong;

Llong A[4];
int Sum,Ans[4];
void input()
{
	int i,a,b,c;
	for(i=0;i<4;++i)
	{
		cin>>a>>b>>c;
		A[i]=a*1000000+b*1000+c;
	}
}
void solve()
{
	int i,j,k,p;
	Llong s,a,b,c;
	Sum=404;
	for(i=0;i<100;++i)
	{
		a=A[1]*i;
		for(j=0;j<100;++j)
		{
			b=A[2]*j;
			for(k=0;k<100;++k)
				if(i!=0 || j!=0 || k!=0)
				{
					c=A[3]*k;
					s=a+b+c;
					if(s%A[0] == 0)
					{
						p=s/A[0];
						if(Sum > i+j+k+p)
						{
							Sum=i+j+k+p;
							Ans[0]=i; Ans[1]=j; 
							Ans[2]=k; Ans[3]=p;
						}
					}
				}
		}
	}
}
void output()
{
	int i;
	if(Sum == 404)
		cout<<"NONE"<<endl;
	else {
		for(i=0;i<3;++i)
			cout<<Ans[i]<<" ";
		cout<<Ans[3]<<endl;
	}
}
int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	input();
	solve();
	output();
	return 0;
}