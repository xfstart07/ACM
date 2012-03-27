/*
ID: xfstart2
LANG: C++
PROG: concom
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int N,M;
int F[101][101];
inline int max(int x,int y)
{ return x>y?x:y; }
void dfs(int x,int y)
{
	for(int i=1;i<=M;++i)
		if(i!=x&&i!=y && F[x][i] <= 50)
		{
			F[x][i]+=F[y][i];
			if(F[x][i] > 50)
				dfs(x,i);
		}
}
int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&N);
	memset(F,0,sizeof(F));
	M=0;
	for(int i=1,a,b,c;i<=N;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		F[a][b]=c;
		M=max(M,max(a,b));
	}
	for(int i=1;i<=M;++i)
		for(int j=1;j<=M;++j)
			if(i!=j && F[i][j] > 50)
				dfs(i,j);
	for(int i=1;i<=M;++i)
		for(int j=1;j<=M;++j)
			if(i!=j && F[i][j] > 50)
				printf("%d %d\n",i,j);
	return 0;
}