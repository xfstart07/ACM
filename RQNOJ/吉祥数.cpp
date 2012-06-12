/*Ä£Äâ*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long k,n,a[255];
    bool b[255];
    cin>>k;
    n=0;
    while(cin>>a[++n]){ if(n==10) break; }
    memset(b,0,sizeof(b));
    for(int t=2;t<=k+1;++t){
        bool c[256];
        memset(c,0,sizeof(c));
        for(long i=1;i<=n;++i) if(!b[i]){
            long p=a[i],s=0;
            while(p){
                long pi=p%10,pj=1;
                for(int j=1;j<=t;++j) pj*=pi;
                p/=10;
                s+=pj;
            }
            if(s<256) c[s]=1;
        }
        for(long i=1;i<=n;++i)
            b[i]=b[i] | c[a[i]];
    }
    long d[255],l=0;
    for(long i=1;i<=n;++i) if(!b[i])
        d[++l]=a[i];
    for(long i=1;i<l;++i)
        for(long j=i+1;j<=l;++j)
            if(d[i]>d[j]){
                long tmp=d[i]; d[i]=d[j]; d[j]=tmp;
            }
    for(long i=1;i<=l;++i) cout<<d[i]<<' ';
    return 0;
}
