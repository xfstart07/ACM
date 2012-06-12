#include<cstdio>
#include<cstring>
using namespace std;

const int INF=-0xFFFFFFF;
int N,M,T;
int Ans;
int f[1010][1010];
inline int min(int x,int y)
{ return x>y?y:x; }
int main()
{
	scanf("%d%d%d",&N,&M,&T);
	memset(f,128,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=N;++i){
		int t,w; scanf("%d%d",&t,&w);
		for(int j=T;j>=t;--j)
			for(int k=min(i,M);k>=1;--k)
				if(f[j][k]<f[j-t][k-1]+w)
					f[j][k]=f[j-t][k-1]+w;
	}
	Ans=INF;
	for(int i=T;i>=0;--i)
		if(f[i][M]>Ans) Ans=f[i][M];
	if(Ans>0) printf("%d\n",Ans);
	else printf("0\n");
	return 0;
}