#include<iostream>
using namespace std;

int main()
{
    int n,MAX,a[1000],b[1000],c[1000];
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        b[i]=c[i]=1;
    }
    MAX=1;
    for(int i=1;i<n;++i){
        for(int j=i-1;j>=0;--j)
            if(a[j]>=a[i]&&b[i]<b[j]+1)
                b[i]=b[j]+1;
        if(b[i]>MAX) MAX=b[i];
    }
    printf("%d",MAX);
    MAX=1;
    for(int i=1;i<n;++i){
        for(int j=i-1;j>=0;--j)
            if(a[i]>a[j]&&c[i]<c[j]+1)
                c[i]=c[j]+1;
        if(c[i]>MAX) MAX=c[i];
    }
    printf(" %d\n",MAX);
    return 0;
}
