/*
ID: xfstart2
LANG: C++
PROG: agrinet
*/
#include<cstdio>
#include<cstring>
using namespace std;

const int INF=0xFFFFFFF;
int N;
bool V[101];
int G[101][101];

void init()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%d",&G[i][j]);
}
void solve()
{
	int res=0;
	memset(V,1,sizeof(V));
	V[1]=0;
	for(int i=1;i<N;++i)
	{
		int Min=INF,Mj;
		for(int j=1;j<=N;++j)
			if(V[j] && Min > G[1][j])
				Min=G[1][j],Mj=j;
		res+=Min;
		V[Mj]=0;
		for(int j=1;j<=N;++j)
			if(V[j] && G[1][j] > G[Mj][j])
				G[1][j]=G[Mj][j];
	}
	printf("%d\n",res);
}
int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	init();
	solve();
	return 0;
}