/* 0/1±³°üÀ©Õ¹*/
#include<iostream>
using namespace std;

long w[501],f[5001],p[501][5001];
int main()
{
    long n,v,c,x;
    scanf("%d %d",&n,&v);
    for(int i=0;i<=v;++i) f[i]=0;
    for(long i=1;i<=n;++i){
        scanf("%d %d %d",&w[i],&c,&x);
        w[i]*=x; c*=x;
        for(long j=v;j>=w[i];--j){
            p[i][j]=0;
            if(f[j]<f[j-w[i]]+c){
                f[j]=f[j-w[i]]+c;
                p[i][j]=i;
            }
        }
    }
    printf("%d\n",f[v]);
    long l=0,ans[501];
    for(int i=n;i>=1;--i){
        if(p[i][v]){
            ans[++l]=p[i][v];
            v-=w[p[i][v]];
        }
    }
    for(long i=l;i>1;--i) printf("%d ",ans[i]);
    printf("%d\n",ans[1]);
    return 0;
}
