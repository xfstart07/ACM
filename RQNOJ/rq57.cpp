#include<cstdio>
#include<cstring>
using namespace std;

int N;
int M,R;
int f[110][110];
int g[110][110];
int rmb[110],rp[110],time[110];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d%d%d",&rmb[i],&rp[i],&time[i]);
	scanf("%d%d",&M,&R);
	for(int i=1;i<=N;++i){
		for(int j=M;j>=rmb[i];--j)
			for(int k=R;k>=rp[i];--k)
				if(f[j][k]<f[j-rmb[i]][k-rp[i]]+1){
					f[j][k]=f[j-rmb[i]][k-rp[i]]+1;
					g[j][k]=g[j-rmb[i]][k-rp[i]]+time[i];
				}
				else if(f[j][k]==f[j-rmb[i]][k-rp[i]]+1){
					if(g[j][k]>g[j-rmb[i]][k-rp[i]]+time[i])
						g[j][k]=g[j-rmb[i]][k-rp[i]]+time[i];
				}
	}
	printf("%d\n",g[M][R]);
	return 0;
}