#include<iostream>
#include<cmath>
using namespace std;

long make(long k){
    long s=1,m=(long)sqrt(k);
    for(int i=2;i<=m;++i)
        if(k%i==0) s+=i+k/i;
    if(m*m==k) s-=m;
    return s;
}
int main()
{
    long a,b,ans=0;
    cin>>a>>b;
    for(long i=a;i<=b;++i){
        long k=make(i);
        if(i>=k||k>100000000||k-i>100000) continue;
        long p=make(k);
        if(p==i) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
