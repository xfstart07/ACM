/*
ID: xfstart2
LANG: C++
PROG: numtri
*/
#include<cstdio>
using namespace std;

long N;
long F[1001][1001];
inline long max(long a,long b)
{ return a>b?a:b; }
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int i,j;
	scanf("%ld",&N);
	for(i=1;i<=N;++i)
		for(j=1;j<=i;++j)
			scanf("%ld",&F[i][j]);
	for(i=N-1;i>0;--i)
		for(j=1;j<=i;++j)
			F[i][j]+=max(F[i+1][j],F[i+1][j+1]);
	printf("%ld\n",F[1][1]);
	return 0;
}