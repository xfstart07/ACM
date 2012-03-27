/*
ID: xfstart2
LANG: C++
PROG: holstein
*/
#include<cstdio>
#include<cstring>

int N,M,L;
int Ans[26];
int tmp[26];
int cot[26];
int V[26];
int G[16][26];
void init()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",V+i);
	scanf("%d",&M);
	for(int i=1;i<=M;++i)
		for(int j=1;j<=N;++j)
			scanf("%d",&G[i][j]);
}
bool check()
{
	for(int i=1;i<=N;++i)
		if(V[i]>cot[i])
			return 0;
	return 1;
}
void dfs(int k,int l)
{
	if(check())
	{
		if(l==0||l>L) return;
		if(l<L) L=l,memcpy(Ans,tmp,sizeof(tmp));
		for(int i=1;i<=l;++i)
			if(Ans[i]>tmp[i])
				break;
			else if(Ans[i]<tmp[i])
				return;
		memcpy(Ans,tmp,sizeof(tmp));
	}
	else if(k<=M){
		for(int i=1;i<=N;++i)
			cot[i]+=G[k][i];
		tmp[l+1]=k;
		dfs(k+1,l+1);
		for(int i=1;i<=N;++i)
			cot[i]-=G[k][i];
		dfs(k+1,l);
	}
}
void solve()
{
	L=M+1;
	memset(cot,0,sizeof(cot));
	dfs(1,0);
	printf("%d ",L);
	for(int i=1;i<L;++i)
		printf("%d ",Ans[i]);
	printf("%d\n",Ans[L]);
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	init();
	solve();
	return 0;
}