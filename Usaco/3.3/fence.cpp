/*
ID: xfstart2
LANG: C++
PROG: fence
*/
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=501,MAXF=1025;

int F,L,N;
int ans[MAXF];
int into[MAXN];
int map[MAXN][MAXN];

	
int max(int x,int y){
	if(x>y) return x;
	else return y;
}
void input()
{
	int i,a,b;
	
	scanf("%d",&F);
    memset(into,0,sizeof(into));
    memset(map,0,sizeof(map));
	N=0;
	for(i=0;i<F;++i)
	{
		scanf("%d%d",&a,&b);
        map[a][b]++; map[b][a]++;
        into[a]++; into[b]++;
		N=max(N,max(a,b));
	}
}
void dfs(int n)
{
	int i;
	for(i=1;i<=N;++i)
		if(map[n][i])
		{
			map[n][i]--; map[i][n]--;
			dfs(i);
		}
	ans[++L]=n;
}
void solve()
{
 int i,n=0;
	for(i=1;i<=N;++i)
		if(into[i]%2)
		{
			n=i; break;
		}
	L=0;
	if(n) dfs(n);
	else dfs(1);
}
void output()
{
	int i;
	for(i=L;i>0;--i)
		printf("%d\n",ans[i]);
}
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
	input();
	solve();
	output();
	return 0;
}
