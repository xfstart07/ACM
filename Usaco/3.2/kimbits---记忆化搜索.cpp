/*
ID: xfstart2
LANG: C++
PROG: kimbits
*/
#include<iostream>
#include<cstdio>
using namespace std;

#define MAXN 32

int N,M;
long long L;
long long F[MAXN][MAXN];

void input()
{
	cin>>N>>M>>L;
}
long long dp(int n,int m)
{
	if(n == 0 || m==0)
		return 1;
	if(F[n][m])
		return F[n][m];
	F[n][m]=dp(n-1,m)+dp(n-1,m-1);
	return F[n][m];
}
void output()
{
	int i;
	long long k;
	L--;
	for(i=N;i>0;--i)
		if((k=dp(i-1,M)) <= L)
		{
			cout<<1;
			L-=k;
			M--;
		}
		else
			cout<<0;
	cout<<endl;
}
int main()
{
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	input();
	output();
	return 0;
}