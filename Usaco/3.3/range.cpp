/*
ID: xfstart2
LANG: C++
PROG: range
*/
#include<cstdio>
#include<cstring>
using namespace std;

int N,L;
int S[255][255];
void input()
{
	int i,j;
	char ch[255];
	scanf("%d",&N);
	memset(S,0,sizeof(S));
	for(i=1;i<=N;++i)
	{
		scanf("%s",ch);
		for(j=1;j<=N;++j)
			S[i][j]=ch[j-1]-'0';
	}
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
			S[i][j]+=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
}
void solve()
{
	int i,j,x,y,res;
	L=2;
	while(true)
	{
		res=0;
		for(j=1;j<=N-L+1;++j)
			for(i=1;i<=N-L+1;++i)
			{
				x=i+L-1; y=j+L-1;
				if(S[x][y]-S[x][j-1]-S[i-1][y]+S[i-1][j-1] == L*L)
					res++;
			}
		if(res)
			printf("%d %d\n",L,res);
		else
			return;
		L++;
	}
}
int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	input();
	solve();
	return 0;
}