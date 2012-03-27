/*
ID: xfstart2
LANG: C++
PROG: spin
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int S[5],L[5];
int A[5][5],B[5][5];
int hash[360];

void input()
{
	int i,j;
	for(i=0;i<5;++i)
	{
		cin>>S[i]>>L[i];
		for(j=0;j<L[i];++j)
			cin>>A[i][j]>>B[i][j];
	}
}
int solve()
{
	int i,j,k,t;
	for(t=0;t<360;++t)
	{
		memset(hash,0,sizeof(hash));
		for(i=0;i<5;++i)
		{
			for(j=0;j<L[i];++j)
			{
				for(k=A[i][j];k<=A[i][j]+B[i][j];++k)
					hash[(k+S[i]*t)%360]++;
			}
		}
		
		for(i=0;i<360;++i)
			if(hash[i] == 5)
				return t;
	}
	
	return 360;
}

void output(int res)
{
	if(res == 360)
		cout<<"none"<<endl;
	else
		cout<<res<<endl;
}
int main()
{
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	
	input();
	output(solve());
	return 0;
}