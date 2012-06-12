#include<iostream>
using namespace std;

int n,m;
int a[110][110];
int f[110][110];
int main()
{
    char s[1000];
    scanf("%d%d",&n,&m);
    gets(s);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
        gets(s);
    }
    memset(f,0,sizeof(f));
    for(int k=1;k<=n;++k)
        for(int i=1;i<=m;++i){
            f[k][i]=f[k-1][i];
            if(f[k][i-1]>f[k][i])
                f[k][i]=f[k][i-1];
            for(int j=1;j<=i;++j)
                if(f[k][i]<f[k-1][i-j]+a[k][j])
                    f[k][i]=f[k-1][i-j]+a[k][j];
        }
    printf("%d\n",f[n][m]);
    return 0;
}

