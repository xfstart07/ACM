/*
01±³°ü
*/
#include<iostream>
using namespace std;

int main()
{
    int n,v,w,c;
    scanf("%d %d",&v,&n);
    int f[v+1];
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;++i){
        scanf("%d %d",&w,&c);
        for(int j=v;j>=w;--j)
            if(f[j]<f[j-w]+c)
                f[j]=f[j-w]+c;
    }
    printf("%d\n",f[v]);
    return 0;
}
