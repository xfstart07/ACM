#include<iostream>
using namespace std;

struct arr{
    long x,y,c;
}queue[400000];
int n,m,g[2002][2002];
int main()
{
    const int d[4][2]={-1,0,0,-1,1,0,0,1};
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&g[i][j]);
    for(int i=0;i<=n;++i) g[i][0]=g[i][m+1]=1;
    for(int i=0;i<=m;++i) g[0][i]=g[n+1][i]=1;
    int x1,y1,ex,ey;
    scanf("%d %d %d %d",&x1,&y1,&ex,&ey);
    int h,t;
    h=t=1;
    queue[1].x=x1; queue[1].y=y1; queue[1].c=0;
    bool bo=0;
    while(h<=t){
        int x,y;
        x=queue[h].x; y=queue[h].y;
        for(int i=0;i<4;++i)
            if(!g[d[i][0]+x][d[i][1]+y]){
                queue[++t].x=d[i][0]+x;
                queue[t].y=d[i][1]+y;
                queue[t].c=queue[h].c+1;
                if(d[i][0]+x==ex&&d[i][1]+y==ey){ bo=1; break; }
            }
        if(bo) break;
        h++;
    }
    if(bo) printf("%d\n",queue[t].c);
    else printf("No Answer!\n");
    return 0;
}
