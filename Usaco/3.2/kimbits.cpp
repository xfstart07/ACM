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
void solve()
{
	int i,j;
	for(i=0;i<=N;++i) F[i][0]=1;
	for(i=0;i<=M;++i) F[0][i]=1;
	for(i=1;i<=N;++i)
		for(j=1;j<=M;++j)
			F[i][j]=F[i-1][j]+F[i-1][j-1];
}
void output()
{
	int i;
	L--;
	for(i=N;i>0;--i)
		if(F[i-1][M] <= L)
		{
			cout<<1;
			L-=F[i-1][M];
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
	solve();
	output();
	return 0;
}