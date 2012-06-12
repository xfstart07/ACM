#include<iostream>
using namespace std;

struct arr{
    long x,y,c;
};
long r,c,h,t;
arr list[450];
char a[22][22];
int main()
{
    const long d[4][2]={-1,0,0,-1,1,0,0,1};
    scanf("%d %d\n",&c,&r);
    for(long i=1;i<=r;++i){
        for(long j=1;j<=c;++j){
            scanf("%c",&a[i][j]);
            if(a[i][j]=='@'){
                list[1].x=i;
                list[1].y=j;
                list[1].c=1;
                a[i][j]='#';
            }
        }
        getchar();
    }
    for(long i=0;i<=r;++i) a[i][0]=a[i][c+1]='#';
    for(long i=0;i<=c;++i) a[0][i]=a[r+1][i]='#';
    h=t=1;
    while(h<=t){
        long xi,yi;
        xi=list[h].x;
        yi=list[h].y;
        for(long i=0;i<4;++i)
            if(a[d[i][0]+xi][d[i][1]+yi]!='#'){
                t++;
                list[t].x=d[i][0]+xi;
                list[t].y=d[i][1]+yi;
                list[t].c=list[h].c+1;
                a[d[i][0]+xi][d[i][1]+yi]='#';
            }
        h++;
    }
    printf("%d\n",t);
    return 0;
}
