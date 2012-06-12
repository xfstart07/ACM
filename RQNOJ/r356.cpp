#include<cstdio>
#include<cstring>
using namespace std;

int N,M,P;
int x[1001],y[1001];
int f[101][101];
int main()
{
	scanf("%d%d%d",&N,&M,&P);
	for(int i=1;i<=P;++i)
		scanf("%d%d",&x[i],&y[i]);
	memset(f,0x7F,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=P;++i){
		for(int j=N;j>=x[i];--j)
			for(int k=M-1;k>=y[i];--k){
				if(f[j][k]>f[j-x[i]][k-y[i]]+1)
					f[j][k]=f[j-x[i]][k-y[i]]+1;
			}
	}
	int ans=10000000;
	for(int i=0;i<M;++i)
		if(f[N][i]<ans)
			ans=f[N][i];
	if(ans==10000000) printf("mty zhen mei yong!\n");
	else printf("%d\n",ans);
	return 0;
}