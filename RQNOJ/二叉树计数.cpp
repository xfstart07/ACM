#include<iostream>
using namespace std;

int gcd(long x,long y){
    int z;
    while(x){
        z=x;
        x=y%x;
        y=z;
    }
    return y;
}
int main()
{
    int n,a[22],b[22];
    cin>>n;
    for(int i=2;i<=n;++i){
        a[i]=n+i;
        b[i]=i;
    }
    for(int i=2;i<=n;++i)
        for(int j=2;j<=n;++j)
            if(b[j]>1){
                int k=gcd(a[i],b[j]);
                a[i]/=k;
                b[j]/=k;
                if(a[i]==1) break;
            }
    long long ans=1;
    for(int i=2;i<=n;++i) ans*=a[i];
    cout<<ans<<endl;
    return 0;
}
