/*
ID: xfstart2
LANG: C++
PROG: game1
*/
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=101;
int N;
int A[MAXN];
int S[MAXN];
int F[MAXN][MAXN];

void input()
{
	int i;
	scanf("%d",&N);
	S[0]=0;
	for(i=1;i<=N;++i)
		scanf("%d",A+i),S[i]=A[i]+S[i-1];
}
int max(int x,int y)
{
	return x>y?x:y;
}
void solve()
{
	int l,i,j;
	for(i=1;i<=N;++i)
		F[i][i]=A[i];
	for(l=2;l<=N;++l)
		for(j=l;j<=N;++j)
		{
			i=j-l+1;
			F[i][j]=max(A[i]+S[j]-S[i]-F[i+1][j],A[j]+S[j-1]-S[i-1]-F[i][j-1]);
		}
}
void output()
{
	printf("%d %d\n",F[1][N],S[N]-F[1][N]);
}
int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	input();
	solve();
	output();
	return 0;
}