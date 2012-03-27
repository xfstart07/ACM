/*
 ID: xfstart2
 LANG: C++
 PROG: ditch
 */
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 210
#define INF 0xFFFFFFF

int N,M;
int u[MAXN][MAXN];  //»¡
int pre[MAXN];
bool vis[MAXN];

void input()
{
    scanf("%d%d",&M,&N);
    int i;
    memset(u,0,sizeof(u));
    for(i=1;i<=M;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        u[a][b]+=c;
    }
}

bool BFS()
{
    queue<int> Q;
    int i;
    memset(vis,false,sizeof(vis));
    Q.push(1);
    vis[1]=true;
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(i=1;i<=N;++i)
            if(u[x][i] > 0 && !vis[i])
            {
                Q.push(i);
                vis[i]=true;
                pre[i]=x;
            }
    }
    return vis[N];
}
void solve()
{
    int i,res=0;
    memset(pre,0,sizeof(pre));
    for(;BFS();)
    {
        int flow=INF;
        for(i=N;i!=1;i=pre[i])
            if(flow > u[pre[i]][i])
                flow=u[pre[i]][i];
        for(i=N;i!=1;i=pre[i])
        {
            u[pre[i]][i]-=flow;
            u[i][pre[i]]+=flow;
        }
        res+=flow;
    }
    printf("%d\n",res);
}
int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    
    input();
    solve();
    return 0;
}
