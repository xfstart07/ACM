#include<iostream>
using namespace std;

int n,m,a[2][101][101],k;
bool check(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    return 0;
}
int main()
{
    const int d[8][2]={-1,0,1,0,0,-1,0,1,-1,-1,1,-1,-1,1,1,1};
    int t;
    scanf("%d %d %d\n",&m,&n,&t);
    k=0;
    char ch;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ch=getchar();
            a[k][i][j]=ch-'0';
        }
        getchar();
    }
    while(t>1){
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                int p=0;
                for(int di=0;di<8;++di)
                    if(check(d[di][0]+i,d[di][1]+j))
                        if(a[k][d[di][0]+i][d[di][1]+j]) p++;
                if(a[k][i][j]){
                    if(p<2||p>3) a[1-k][i][j]=0;
                    if(p==2||p==3) a[1-k][i][j]=1;
                }
                else{
                    if(p==3) a[1-k][i][j]=1;
                    else a[1-k][i][j]=0;
                }
            }
        k=1-k;
        --t;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
           printf("%d",a[k][i][j]);
        printf("\n");
    }
    return 0;
}
