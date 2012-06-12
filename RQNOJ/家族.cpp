#include<iostream>
using namespace std;

int n,m,p,a[5001];
int find(long x){
    if(x!=a[x]) a[x]=find(a[x]);
    return a[x];
}
int main()
{
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;++i) a[i]=i;
    int x,y,xi,yi;
    for(int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        xi=find(x); yi=find(y);
        if(xi!=yi) a[yi]=xi;
    }
    for(int i=1;i<=p;++i){
        scanf("%d %d",&x,&y);
        xi=find(x); yi=find(y);
        if(xi!=yi) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
