#include<iostream>
using namespace std;

int main()
{
    __int64 n,f[131][131];
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            for(int k=0;k<j;++k)
                f[i][j]+=f[i-j][k];
    __int64 ans=0;
    for(int i=1;i<=n;++i) ans+=f[n][i];
    cout<<ans-1<<endl;
    return 0;
}
