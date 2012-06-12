#include<iostream>
using namespace std;

int n,G[55][55],u[55][55];
int dis[55];
int pre[55];
bool vis[55];
int MAX,ans,N;
void bfs(){
    int que[55],h,t;
    memset(vis,0,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    que[1]=1;
    h=t=1;
    dis[1]=1;
    vis[1]=1;
    while(h<=t){
        int cur=que[h++];
        for(int i=1;i<=n;++i)
            if(u[cur][i]&&!vis[i]){
                vis[i]=1;
                que[++t]=i;
                dis[i]=dis[cur]+1;
            }
    }
}
void dfs(int cur){
    if(!u[pre[cur]][cur]&&cur!=1) return;
    if(cur==N){
        int MIN=0xFFFFFFF;
        for(int i=N;i!=1;i=pre[i])
            if(u[pre[i]][i]<MIN) MIN=u[pre[i]][i];
        MAX+=MIN;
        for(int i=N;i!=1;i=pre[i]){
            u[pre[i]][i]-=MIN;
            u[i][pre[i]]+=MIN;
        }
        return;
    }
    for(int i=1;i<=n;++i)
        if(u[pre[cur]][cur]||cur==1)
            if(u[cur][i]&&dis[i]==dis[cur]+1){
                pre[i]=cur;
                dfs(i);
            }
}
void flow(){
    memset(pre,0,sizeof(pre));
    while(1){
        bfs();
        if(!vis[N]) break;
        dfs(1);
    }
}
int main()
{
    scanf("%d\n",&n);
    char ch;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ch=getchar();
            G[i][j]=ch-'0';
        }
        getchar();
    }
    ans=0xFFFFFFF;
    for(int i=2;i<=n;++i){
        N=i;
        memcpy(u,G,sizeof(G));
        MAX=0;
        flow();
        if(MAX<ans) ans=MAX;
    }
    printf("%d\n",ans);
    return 0;
}
