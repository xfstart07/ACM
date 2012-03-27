/*
ID: xfstart2
LANG: C++
PROG: maze1
*/
#include<cstdio>
using namespace std;

int N,M;
int Ex,Ey;
bool F[210][80];
int H,T,que[20000][3];
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
void init()
{
	scanf("%d%d",&M,&N);
	getchar();
	N=2*N+1; M=2*M+1;
	char c; H=1; T=0;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j)
		{
			c=getchar();
			if(c=='+' || c=='-'||c=='|')
				F[i][j]=0;
			else {
				F[i][j]=1;
				if(i==1||i==N||j==1||j==M)
					que[++T][0]=i,que[T][1]=j,que[T][2]=1;
			}
		}
		getchar();
	}
}
void solve()
{
	int x,y;
	while(H<=T) {
		x=que[H][0]; y=que[H][1];
		for(int k=0;k<4;++k)
			if(F[x+dx[k]][y+dy[k]]) {
				F[x+dx[k]][y+dy[k]]=0;
				T++;
				que[T][0]=x+dx[k];
				que[T][1]=y+dy[k];
				que[T][2]=que[H][2]+1;
			}
		H++;
	}
	int Ans=0;
	for(int i=1;i<=T;++i)
		if(que[i][2] > Ans)
			Ans=que[i][2];
	printf("%d\n",(int)(Ans/2));
}
int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	init();
	solve();
	return 0;
}