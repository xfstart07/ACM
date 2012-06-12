#include<iostream>
using namespace std;

int main()
{
    int n;
    double d1,c,d2,p,left,ans,d[105],a[105],maxn;
    scanf("%lf %lf %lf %lf %d",&d1,&c,&d2,&p,&n);
    for(int i=1;i<=n;++i) scanf("%lf %lf",&d[i],&a[i]);
    d[0]=0; a[0]=p;
    d[n+1]=d1; a[n+1]=99999.99999;
    left=ans=0;
    int i=0;
    maxn=c*d2;
    bool bo=1;
    while(i<=n){
        int k=i+1;
        if(d[k]-d[k-1]>maxn){
            bo=0;
            break;
        }
        while(k+1<=n&&d[k+1]-d[i]<=maxn) k++;
        bool bk=1;
        for(int j=i+1;j<=k;++j)
            if(a[j]<a[i]){
                ans+=(d[j]-d[i]-left)/d2*a[i];
                i=j;
                left=0;
                bk=0;
            }
        if(bk){
            double min=99999999.9;
            int minj;
            for(int j=i+1;j<=k;++j)
                if(min>a[j]){
                    min=a[j];
                    minj=j;
                }
            if(d[minj]-d[i]+d1-d[minj]>maxn){
                ans+=(maxn-left)/d2*a[i];
                left=maxn-(d[minj]-d[i]);
            }
            else{
                ans+=(d[minj]-d[i]+d1-d[minj]-left)/d2*a[i];
                left=d1-d[minj];
            }
            i=minj;
        }
    }
    if(bo) printf("%0.2lf\n",ans);
    else printf("No Solution\n");
    return 0;
}
