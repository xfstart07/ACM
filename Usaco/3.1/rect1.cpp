/*
ID: xfstart2
LANG: C++
PROG: rect1
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1001;

int N,R,C;
int T,color[2510];
int X1[MAXN],Y1[MAXN],X2[MAXN],Y2[MAXN],col[MAXN];
void init()
{
	int i;
	cin>>R>>C>>N;
	for(i=1;i<=N;++i)
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i]>>col[i];
	X1[0]=Y1[0]=0; X2[0]=R; Y2[0]=C; col[0]=1;
}
void cal(int x1,int y1,int x2,int y2,int n)
{
	while(n<=N && (x1>=X2[n] || y1>=Y2[n] || x2<=X1[n] || y2<=Y1[n]))
		n++;
	if(n>N)
	{
		color[T]+=(x2-x1)*(y2-y1);
		return;
	}
	if(x1<X1[n])
	{
		cal(x1,y1,X1[n],y2,n+1);
		x1=X1[n];
	}
	if(x2>X2[n])
	{
		cal(X2[n],y1,x2,y2,n+1);
		x2=X2[n];
	}
	if(y1<Y1[n])
	{
		cal(x1,y1,x2,Y1[n],n+1);
		y1=Y1[n];
	}
	if(y2>Y2[n])
		cal(x1,Y2[n],x2,y2,n+1);
}
void solve()
{
	int i;
	memset(color,0,sizeof(color));
	for(i=N;i>=0;--i)
	{
		T=col[i];
		cal(X1[i],Y1[i],X2[i],Y2[i],i+1);
	}
	for(i=1;i<=2500;++i)
		if(color[i])
			cout<<i<<" "<<color[i]<<endl;
}
int main()
{
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	init();
	solve();
	return 0;
}