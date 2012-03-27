/*
ID: xfstart2
LANG: C++
PROG: stamps
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=2000010;
int N,K;
int MAX;
int F[MAXN],A[51];
void init()
{
	int i;
	scanf("%d%d",&K,&N);
	MAX=0;
	for(i=1;i<=N;++i)
	{
		scanf("%d",A+i);
		if(A[i]>MAX)
			MAX=A[i];
	}
}
void solve()
{
	int i,j;
	F[0]=0;
	for(i=1;i<=MAX*K;++i)
	{
		F[i]=K+1;
		for(j=1;j<=N;++j)
				if(i>=A[j])
					if(F[i] > F[i-A[j]]+1)
						F[i]=F[i-A[j]]+1;
	}
	F[MAX*K+1]=K+1;
	int res=1;
	while(F[res] != K+1) res++;
	printf("%d\n",res-1);
}
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	init();
	solve();
	return 0;
}