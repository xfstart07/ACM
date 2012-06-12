#include<iostream>
using namespace std;

const int d[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,f[101][101],a[101][101];
int dfs(int x,int y){
    if(f[x][y]) return f[x][y];
    int t,tmp;
    t=1;
    for(int i=0;i<4;++i)
        if(d[i][0]+x>0&&d[i][0]+x<=n&&d[i][1]+y>0&&d[i][1]+y<=m)
            if(a[x][y]<a[d[i][0]+x][d[i][1]+y]){
                tmp=dfs(d[i][0]+x,d[i][1]+y)+1;
                if(tmp>t) t=tmp;
            }
    f[x][y]=t;
    return t;
}
int main()
{
    int MAX=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            int k=dfs(i,j);
            if(k>MAX) MAX=k;
        }
    cout<<MAX<<endl;
    return 0;
}
