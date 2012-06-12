#include<iostream>
#define min(a,b)(a>b?b:a)
using namespace std;

int main()
{
    int n,a[30001],f1[30001],f2[30001];
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    f1[0]=f2[0]=0;
    for(int i=1;i<=n;++i)
        if(a[i]==1){
            f1[i]=f1[i-1];
            f2[i]=min(f1[i-1],f2[i-1]+1);
        }
        else{
            f1[i]=f1[i-1]+1;
            f2[i]=min(f1[i-1]+1,f2[i-1]);
        }
    if(f1[n]>f2[n]) printf("%d\n",f2[n]);
    else printf("%d\n",f1[n]);
    return 0;
}
