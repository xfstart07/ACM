#include<iostream>
using namespace std;

int main()
{
    long long a[300];
    int n,b[300],c[300];
    cin>>n;
    for(int i=0;i<n;++i){
        long x,y,z;
        cin>>x>>y>>z;
        b[i]=i+1; c[i]=x+y+z;
        a[i]=c[i]*1000000+x*1000+(100-i-1);
        
    }
    for(int i=0;i<n-1;++i)
        for(int j=i+1;j<n;++j)
            if(a[j]>a[i]){
                long long tmp=a[i]; a[i]=a[j]; a[j]=tmp;
                tmp=b[i]; b[i]=b[j]; b[j]=tmp;
                tmp=c[i]; c[i]=c[j]; c[j]=tmp;
            }
    for(int i=0;i<5;++i)
        cout<<b[i]<<' '<<c[i]<<endl;
    return 0;
}
