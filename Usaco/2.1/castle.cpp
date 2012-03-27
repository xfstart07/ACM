/*
ID: xfstart2
LANG: C++
PROG: castle
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct Node{
	int num,sum;
	bool f[4];
};
int N,M;
int Num,Sum;
Node G[50][50];
bool T[50][50],TG[50][50];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
void init()
{
	cin>>M>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			for(int p=0;p<4;++p) G[i][j].f[p]=1;
			int k,d=8,p=3; cin>>k;
			while(k)
			{
				if(k>=d)
				{	
					G[i][j].f[p]=0;
					k-=d; 
				}
				d/=2; p--;
			}
		}
	}
}
void flood(int x,int y)
{
	T[x][y]=0;
	G[x][y].num=Num;
	Sum++;
	for(int k=0;k<4;++k)
	{
		int kx=dx[k]+x,ky=dy[k]+y;
		if(kx>=0 && kx<N && ky>=0 && ky<M && T[kx][ky] && G[x][y].f[k])
			flood(kx,ky);
	}
}
void fill(int x,int y)
{
	TG[x][y]=0;
	G[x][y].sum=Sum;
	for(int k=0;k<4;++k)
	{
		int kx=dx[k]+x,ky=dy[k]+y;
		if(kx>=0 && kx<N && ky>=0 && ky<M && TG[kx][ky] && G[x][y].f[k])
			fill(kx,ky);
	}
}
void solve()
{
	int Max=0;
	memset(T,1,sizeof(T));
	memset(TG,1,sizeof(TG));
	Num=0;
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(T[i][j])
			{
				Num++;
				Sum=0;
				flood(i,j);
				if(Sum > Max)
					Max=Sum;
				fill(i,j);
			}
	cout<<Num<<endl<<Max<<endl;
	int x,y; char c; Max=0;
	for(int j=0;j<M;++j)
		for(int i=N-1;i>=0;--i)
		{
			if(i-1>=0 && !G[i][j].f[1] && G[i][j].num!=G[i-1][j].num &&
				G[i][j].sum+G[i-1][j].sum > Max)
			{
				x=i; y=j; c='N';
				Max=G[i][j].sum+G[i-1][j].sum;
			}
			if(j+1<M && !G[i][j].f[2] && G[i][j].num!=G[i][j+1].num && 
				G[i][j].sum+G[i][j+1].sum > Max)
			{
				x=i; y=j; c='E';
				Max=G[i][j].sum+G[i][j+1].sum;
			}
		}
	cout<<Max<<endl<<x+1<<" "<<y+1<<" "<<c<<endl;
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	init();
	solve();
	return 0;
}