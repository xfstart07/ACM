#include<cstdio>
#include<cstring>
using namespace std;

struct arr{
	int l,r,c;
}a[1010];
int N,M;
int v[1010];
bool vis[1010];
int f[1010][1010];
int treedp(int x,int y)
{
	if(f[x][y]>=0) return f[x][y];
	int Mk=treedp(a[x].r,y);
	for(int i=0;i<y;++i){
		int k=treedp(a[x].l,i)+treedp(a[x].r,y-1-i)+a[x].c;
		if(k>Mk) Mk=k;
	}
	f[x][y]=Mk;
	return Mk;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i].c);
	memset(v,0,sizeof(v));
	int x,y; 
	while(scanf("%d%d",&x,&y)!=EOF){
		if(v[x]==0) a[x].l=y;
		else a[v[x]].r=y;
		v[x]=y;
	}
	for(int i=0;i<=N;++i)
		for(int j=0;j<=M;++j)
			if(i&&j) f[i][j]=-1;
			else f[i][j]=0;
	treedp(a[0].l,M);
	printf("%d\n",f[a[0].l][M]);
	return 0;
}