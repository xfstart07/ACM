/*
µÝÍÆ
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,a[101],f[101];
    bool g[101][101];
    cin>>n;
    cin.ignore();
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;++i){
        string s;
        getline(cin,s);
        bool bo=1; int k=0;
        for(int j=0;j<s.size();++j)
            if(s[j]==' '){
                if(bo){
                    a[i]=k;
                    bo=k=0;
                }
                else{
                    g[k][i]=1;
                    k=0;
                }
            }
            else k=k*10+s[j]-'0';
        if(bo) a[i]=k;
        else g[k][i]=1;
    }
    for(int i=1;i<=n;++i){
        f[i]=a[i];
        for(int j=i-1;j>=1;--j)
            if(g[i][j]&&f[i]<f[j]+a[i])
                f[i]=f[j]+a[i];
    }
    int MAX=0;
    for(int i=1;i<=n;++i)
        if(f[i]>MAX) MAX=f[i];
    cout<<MAX<<endl;
    return 0;
}
