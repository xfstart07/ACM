#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=501,MAXP=801,MAXC=1500*2,INF=0xFFFFFFF;

struct Edge{
    int pre[MAXP];
    int son[MAXC],dis[MAXC],next[MAXC];
}E;

struct Heap{
    int id,val;
}H[MAXP];

int N,P,C;
int hsize;
int Ans;
int cow[MAXN];
int dis[MAXP];
int pos[MAXP];

void addedge(int a,int b,int c,int& k)
{
    E.next[++k]=E.pre[a];
    E.son[k]=b; E.dis[k]=c; E.pre[a]=k;
    E.next[++k]=E.pre[b];
    E.son[k]=a; E.dis[k]=c; E.pre[b]=k;
}
void input()
{
    int i,a,b,c,k=0;
    scanf("%d%d%d",&N,&P,&C);
    for(i=1;i<=N;++i)
        scanf("%d",cow+i);
    memset(E.pre,0,sizeof(E.pre));
    for(i=1;i<=C;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c,k);
    }
}

void heapup(int n,int v,int h)
{
    int i,j;
    Heap P={n,v};
    for(i=h;P.val<H[j=i/2].val;i=j)
    {
        H[i]=H[j];
        pos[H[i].id]=i;
    }
    H[i]=P;
    pos[P.id]=i;
}
void heapins(int n,int v)
{
    heapup(n,v,++hsize);
}
void heapmodify(int n,int v)
{
    heapup(n,v,pos[n]);
}
void heapdec()
{
    int i,j;
    Heap P=H[hsize];
    hsize--;
    for(i=1;(j=i*2)<=hsize;i=j)
    {
        if(j < hsize && H[j].val > H[j+1].val) j++;
        if(P.val > H[j].val)
        {
            H[i]=H[j];
            pos[H[i].id]=i;
        }
        else
            break;
    }
    H[i]=P;
    pos[P.id]=i;
}
void dijkstra(int n)
{
    int i,x,y;

    hsize=0;
    for(i=1;i<=P;++i)
        heapins(i,dis[i]=INF);
    heapmodify(n,dis[n]=0);
    while(hsize)
    {
        x=H[1].id;
        heapdec();
        for(i=E.pre[x];i;i=E.next[i])
        {
            y=E.son[i];
            if(dis[y] > dis[x] + E.dis[i])
                heapmodify(y,dis[y]=dis[x]+E.dis[i]);
        }
    }
    
    x=0;
    for(i=1;i<=N;++i)
        x+=dis[cow[i]];
    if(Ans > x)
        Ans=x;
}
void solve()
{
    int i;
    Ans=INF;
    for(i=1;i<=P;++i)
        dijkstra(i);
}
void output()
{
    printf("%d\n",Ans);
}
int main()
{
    freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
    input();
    solve();
    output();
    return 0;
}
