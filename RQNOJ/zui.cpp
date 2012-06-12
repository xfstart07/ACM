#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

long n,m,cost[501][500],dis[501];
void input(){
    char s[500];
    scanf("%d %d\n",&m,&n);
    for(long i=1;i<=n;++i)
        for(long j=1;j<=n;++j)
            cost[i][j]=0xFFFFFFF;
    long a[100];
    for(long i=1;i<=m;++i){
        gets(s);
        long k=0; a[0]=0;
        for(long j=0;j<strlen(s);++j)
            if(s[j]==' '){
                a[0]++;
                a[a[0]]=k;
                k=0;
            }
            else k=k*10+s[j]-'0';
        a[0]++; a[a[0]]=k;
        for(long x=1;x<a[0];++x)
            for(long y=x+1;y<=a[0];++y)
                cost[a[x]][a[y]]=1;
    }
}
void solve(){
    bool visit[501];
    for(long i=1;i<=n;++i){
        dis[i]=cost[1][i];
        visit[i]=1;
    }
    dis[1]=0;
    visit[1]=0;
    for(long i=1;i<n;++i){
        long maxn=0xFFFFFFF,maxi;
        for(long j=1;j<=n;++j)
            if(visit[j] && dis[j]<maxn){
                maxn=dis[j]; maxi=j;
            }
        visit[maxi]=0;
        for(long j=1;j<=n;++j)
            if(visit[j] && dis[j]>dis[maxi]+cost[maxi][j])
                dis[j]=dis[maxi]+cost[maxi][j];
    }
}
void output(){
    if(dis[n]>n) printf("NO\n");
    else printf("%d\n",dis[n]-1);
}
int main()
{
    input();
    solve();
    output();
    system("pause");
    return 0;
}
/* http://www.rqnoj.cn/Problem_Show.asp?PID=263  */
