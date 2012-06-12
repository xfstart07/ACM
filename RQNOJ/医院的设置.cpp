#include<iostream>
using namespace std;

int main()
{
    int n,a[101],f[101][101],x,y;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) f[i][j]=0xFFFFFFF;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>x>>y;
        if(x) f[i][x]=f[x][i]=1;
        if(y) f[i][y]=f[y][i]=1;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i) if(i!=k)
            for(int j=1;j<=n;++j) if(i!=j&&j!=k)
                if(f[i][j]>f[i][k]+f[k][j])
                    f[i][j]=f[i][k]+f[k][j];
    int MIN=0xFFFFFFF;
    for(int i=1;i<=n;++i){
        int s=0;
        for(int j=1;j<=n;++j)
            if(i!=j&&f[i][j]!=0xFFFFFFF)
            s+=f[i][j]*a[j];
        if(MIN>s) MIN=s;
    }
    cout<<MIN<<endl;
    return 0;
}
