#include<iostream>
using namespace std;

int n,hd,G[55][55],u[55][55];
int pre[55];
bool vis[55];
int ans,MAX;
void findway(){
    int que[55],h,t;
    h=t=1;
    que[1]=1;
    memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    while(h<=t){
        long now=que[h++];
        for(int i=1;i<=n;++i)
            if(u[now][i]&&!vis[i]){
                vis[i]=1;
                pre[i]=now;
                que[++t]=i;
            }
    }
}
void flow(){
    int best=0xFFFFFFF;
    for(int i=hd;i!=1;i=pre[i])
        if(u[pre[i]][i]<best) best=u[pre[i]][i];
    MAX+=best;
    for(int i=hd;i!=1;i=pre[i]){
        u[pre[i]][i]-=best;
        u[i][pre[i]]+=best;
    }
}
void input()
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
        hd=i;
        memcpy(u,G,sizeof(int)*55*55);
        MAX=0;
        for(;;){
            findway();
            if(!vis[hd]) break;
            flow();
        }
        if(ans>MAX) ans=MAX;
    }
    printf("%d\n",ans);
}
int main()
{
    input();
    return 0;
}
