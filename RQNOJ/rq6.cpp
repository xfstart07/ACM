#include<cstdio>
#include<cstring>
using namespace std;

struct arr{
	int n;
	int w[3],c[3];
}a[61];
int N,v;
int f[3300];
bool bo[61];
int main()
{
	scanf("%d%d",&v,&N); v/=10;
	int v1,p,q;
	for(int i=1;i<=N;++i){
		scanf("%d%d%d",&v1,&p,&q);
		v1/=10; bo[i]=1;
		if(q==0){
			a[i].n=0;
			a[i].w[0]=v1;
			a[i].c[0]=v1*p;
		}
		else{
			a[q].n++;
			a[q].w[a[q].n]=v1;
			a[q].c[a[q].n]=v1*p;
			bo[i]=0;
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=N;++i) if(bo[i])
		for(int j=v;j>=a[i].w[0];--j){
			if(f[j]<f[j-a[i].w[0]]+a[i].c[0])
				f[j]=f[j-a[i].w[0]]+a[i].c[0];
			if(a[i].n>0){
				if(j>=a[i].w[0]+a[i].w[1])
				if(f[j]<f[j-a[i].w[0]-a[i].w[1]]+a[i].c[0]+a[i].c[1])
					f[j]=f[j-a[i].w[0]-a[i].w[1]]+a[i].c[0]+a[i].c[1];
				if(a[i].n==2){
					if(j>=a[i].w[0]+a[i].w[2])
					if(f[j]<f[j-a[i].w[0]-a[i].w[2]]+a[i].c[0]+a[i].c[2])
						f[j]=f[j-a[i].w[0]-a[i].w[2]]+a[i].c[0]+a[i].c[2];
					if(j>=a[i].w[0]+a[i].w[1]+a[i].w[2])
					if(f[j]<f[j-a[i].w[0]-a[i].w[1]-a[i].w[2]]+a[i].c[0]+a[i].c[1]+a[i].c[2])
						f[j]=f[j-a[i].w[0]-a[i].w[1]-a[i].w[2]]+a[i].c[0]+a[i].c[1]+a[i].c[2];
				}
			}
		}
	printf("%d\n",f[v]*10);
	return 0;
}