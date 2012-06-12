/* floodfill */
#include<iostream>
using namespace std;

const int d[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,a[102][102];
void dfs(int x,int y){
    a[x][y]=0;
    for(int i=0;i<4;++i)
        if(a[d[i][0]+x][d[i][1]+y])
            dfs(d[i][0]+x,d[i][1]+y);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;++i) a[i][0]=a[i][m+1]=0;
    for(int i=0;i<=m;++i) a[0][i]=a[n+1][i]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            char c;
            cin>>c;
            if(c!='0') a[i][j]=1;
            else a[i][j]=0;
        }
        cin.ignore();
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]){
                ans++;
                dfs(i,j);
            }
    cout<<ans<<endl;
    return 0;
}
