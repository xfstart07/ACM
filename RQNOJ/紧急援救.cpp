#include<iostream>
using namespace std;

struct arr{
    int x,y,c;
}list[1000000];
int main()
{
    int n,bx,by,ex,ey,h,t;
    bool a[1002][1002];
    char ch;
    const int d[4][2]={0,-1,-1,0,0,1,1,0};
    scanf("%d\n",&n);
    for(int i=0;i<=n;++i)
        a[i][0]=a[i][n+1]=a[0][i]=a[n+1][i]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%c",&ch);
            if(ch=='0') a[i][j]=1;
            else a[i][j]=0;
        }
        getchar();
    }
    scanf("%d %d",&bx,&by);
    scanf("%d %d",&ex,&ey);
    list[1].x=bx;
    list[1].y=by;
    list[1].c=0;
    a[bx][by]=0;
    h=t=1;
    bool bo=0;
    while(h<=t){
        long xi=list[h].x,yi=list[h].y;
        for(int i=0;i<4;++i)
            if(a[d[i][0]+xi][d[i][1]+yi]){
                t++;
                list[t].x=d[i][0]+xi;
                list[t].y=d[i][1]+yi;
                list[t].c=list[h].c+1;
                a[d[i][0]+xi][d[i][1]+yi]=0;
                if(d[i][0]+xi==ex&&d[i][1]+yi==ey){
                    bo=1; break;
                }
            }
        h++;
        
        if(bo) break;
    }
    printf("%d\n",list[t].c);
    return 0;
}
