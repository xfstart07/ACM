/*
DP
*/
#include<iostream>
using namespace std;

int main()
{
    int a[11],n,f[210];
    for(int i=1;i<=10;++i) cin>>a[i];
    cin>>n;
    f[0]=0;
    for(int i=1;i<=n;++i){
        f[i]=0xFFFF;
        for(int j=10;j>=1;--j)
            if(i-j>=0){
               if(f[i]>f[i-j]+a[j])
                   f[i]=f[i-j]+a[j];
            }
        }
    cout<<f[n]<<endl;
    return 0;
}
