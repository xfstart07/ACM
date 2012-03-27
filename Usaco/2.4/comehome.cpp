/*
ID: xfstart2
LANG: C++
PROG: comehome
*/
#include<cstdio>
#include<cstring>

const int N=52,INF=0xFFFFFFF;

int P;
int G[N][N];

inline int make(char c)
{
	if(c>='A' && c<='Z')
		return c-'A';
	return c-'a'+26;
}
void init()
{
	char a[3],b[3]; int c;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			G[i][j]=INF;
	scanf("%d",&P);
	while(P--)
	{
		int ia,ib;
		scanf("%s%s%d",a,b,&c);
		if(G[ia=make(a[0])][ib=make(b[0])] > c)
			G[ia][ib]=G[ib][ia]=c;
	}
}
void solve()
{
	for(int k=0;k<N;++k)
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				if(G[i][j] > G[i][k]+G[k][j])
					G[i][j]=G[i][k]+G[k][j];
	int k,res=INF;
	for(int i=0;i<25;++i)
		if(G[i][25] < res)
			res=G[i][25],k=i;
	printf("%c %d\n",(char)(k+'A'),res);
}
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	init();
	solve();
	return 0;
}