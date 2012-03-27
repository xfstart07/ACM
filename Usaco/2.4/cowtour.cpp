/*
ID: xfstart2
LANG: C++
PROG: cowtour
*/
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN=151,INF=0xFFFFFFF;

int N;
double Ans;
double Max[MAXN],Min[MAXN];
int X[MAXN],Y[MAXN];
double G[MAXN][MAXN];

inline double dist(int i,int j)
{
	return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}
void init()
{
	char c;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d%d",X+i,Y+i);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(i!=j)
				G[i][j]=INF;
			else 
				G[i][j]=0;
	for(int i=1;i<=N;++i)
	{
		getchar();
		for(int j=1;j<=N;++j)
		{
			c=getchar();
			if(c == '1')
				G[i][j]=dist(i,j);
		}
	}
}
void solve()
{
	for(int k=1;k<=N;++k)
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j) 
				if(G[i][j] > G[i][k]+G[k][j])
					G[i][j]=G[i][k]+G[k][j];
	for(int i=1;i<=N;++i)
	{
		Max[i]=0;
		for(int j=1;j<=N;++j)
			if(G[i][j] != INF)
				if(G[i][j] > Max[i])
					Max[i]=G[i][j];
	}
	for(int i=1;i<=N;++i)
	{
		Min[i]=0;
		for(int j=1;j<=N;++j)
			if(G[i][j] < INF)
				if(Min[i] < Max[j])
					Min[i]=Max[j];
	}
	Ans=INF;
	double r1;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(i!=j && G[i][j]==INF)
			{
				if(Min[i]>Min[j])
					r1=Min[i];
				else
					r1=Min[j];
				if(r1 < Max[i]+Max[j]+dist(i,j))
					r1=Max[i]+Max[j]+dist(i,j);
				if(Ans > r1)
					Ans=r1;
			}
	printf("%.6lf\n",Ans);
}
int main()
{
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	init();
	solve();
	return 0;
}