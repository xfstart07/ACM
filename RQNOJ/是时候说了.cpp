#include<iostream>
using namespace std;

int main()
{
    int n,v=99,a[20],b[20],f[100];
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    memset(f,0,sizeof(f));
    for(int i=0;i<n;++i)
        for(int j=v;j>=a[i];--j)
            if(f[j]<f[j-a[i]]+b[i])
                f[j]=f[j-a[i]]+b[i];
    cout<<f[v]<<endl;
    return 0;
}
