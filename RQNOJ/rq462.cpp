#include<iostream>
using namespace std;

int n,s,t,k,m;
int cost[1024][1024];
int dis[1024];
int vis[1024];
int ans;
int dij(int u,int v){
    for(int i=1;i<=n;++i){
        dis[i]=cost[u][i];
        vis[i]=1;
    }
    dis[u]=0;
    vis[u]=0;
    for(int i=1;i<n;++i){
        int min=0x7FFFFFFF,minj;
        for(int j=1;j<=n;++j)
            if(vis[j]&&dis[j]<min){
                min=dis[j];
                minj=j;
            }
        if(minj==v) return dis[v];
        vis[minj]=0;
        for(int j=1;j<=n;++j)
            if(vis[j]&&dis[j]>dis[minj]+cost[minj][j])
                dis[j]=dis[minj]+cost[minj][j];
    }
}
int main()
{
    char ss[100];
    int l;
    scanf("%d%d%d%d%d",&n,&s,&t,&k,&m);
    gets(ss);
    scanf("%d",&l); gets(ss);
    memset(cost,127,sizeof(cost));
    int x,y,c;
    for(int i=1;i<=l;++i){
        scanf("%d%d%d",&x,&y,&c);
        gets(ss);
        if(cost[x][y]>c)
            cost[x][y]=c;
    }
    ans=dij(s,k)+dij(k,t);
    if(ans<=m) printf("Yes\n");
    else printf("No\n");
    printf("%d\n",ans);
    return 0;
}
