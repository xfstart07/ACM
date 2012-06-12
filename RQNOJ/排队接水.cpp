#include<iostream>
using namespace std;

struct arr{
    long x,y;
};
long n;
arr a[901];
int cmp(const void *x,const void *y){
    arr *nox=(arr*)x,*noy=(arr*)y;
    if(nox->x-noy->x) return nox->x-noy->x;
    else return nox->y-noy->y;
}
int main()
{
    scanf("%d",&n);
    for(long i=0;i<n;++i){
        scanf("%d",&a[i].x);
        a[i].y=i+1;
    }
    qsort(a,n,sizeof(arr),cmp);
    for(long i=0;i<n-1;++i) printf("%d ",a[i].y);
    printf("%d\n",a[n-1].y);
    double ans=0.0;
    for(long i=0;i<n-1;++i)
        ans=ans+a[i].x*(n-1-i);
    ans/=n;
    printf("%0.2lf\n",ans);
    return 0;
}
