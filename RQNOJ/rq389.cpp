#include<cstdio>
#include<cstring>
#include<cstdlib>
struct node{
    long index,score;
    node *next;
};
struct arr{
    node *head,*tail;
};
long n,m;
long a[30];
arr g[100001];
char t[30];
void input(){
    scanf("%d %d %s",&n,&m,t);
    for(long i=1;i<=n;++i) g[i].head=g[i].tail=NULL;
    long x,y,z;
    node *now;
    for(long i=1;i<=m;++i){
        scanf("%d %d %d",&x,&y,&z);
        now=new node;
        now->index=y;
        now->score=z;
        now->next=NULL;
        if(g[x].tail==NULL)
            g[x].head=g[x].tail=now;
        else{
            g[x].tail->next=now;
            g[x].tail=now;
        }
        now=new node;
        now->index=x;
        now->score=z;
        now->next=NULL;
        if(g[y].tail==NULL)
            g[y].head=g[y].tail=now;
        else{
            g[y].tail->next=now;
            g[y].tail=now;
        }
    }
}
void add(long long x){
    a[1]+=x;
    for(long i=1;i<=a[0];i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    while(a[a[0]+1]){
        a[0]++;
        a[a[0]+1]+=a[a[0]]/10;
        a[a[0]]%=10;
    }
}
void mul(){
    for(long i=1;i<=a[0];++i)
        a[i]*=2;
    for(long i=1;i<=a[0];++i){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    while(a[a[0]+1]){
        a[0]++;
        a[a[0]+1]+=a[a[0]]/10;
        a[a[0]]%=10;
    }
}
void SPFA(){
    long long dis[n+1];
    long list[n+1],h,t;
    bool hash[n+1];
    for(long i=1;i<=n;++i){
        dis[i]=0xFFFFFFF;
        hash[i]=1;
    }
    list[1]=1;
    h=t=1;
    dis[1]=0;
    hash[1]=0;
    node *now;
    while(h<=t){
        long xi,yi,zi;
        xi=list[(h-1)%n+1];
        now=g[xi].head;
        while(now!=NULL){
            yi=now->index;
            zi=now->score;
            if(dis[yi]>dis[xi]+zi){
                dis[yi]=dis[xi]+zi;
                if(hash[yi]){
                    t++;
                    list[(t-1)%n+1]=yi;
                    hash[yi]=0;
                }
            }
            now=now->next;
        }
        h++;
        hash[xi]=1;
    }
    memset(a,0,sizeof(a));
    a[0]=1;a[1]=0;
    for(long i=1;i<=n;++i)
        add(dis[i]);
    mul();
}
bool check(){
    if(strlen(t)<a[0]) return true;
    else if(a[0]<strlen(t)) return false;
    else for(long i=a[0];i>=1;--i)
        if(a[i]>t[a[0]-i]-'0') return true;
        else if(a[i]<t[a[0]-i]-'0') return false;
    return false;
}
void output(){
    for(long i=a[0];i>=1;--i) printf("%d",a[i]);
    printf("\n");
    if(check()) printf("escape\n");
    else printf("run\n");
}
int main()
{
    input();
    SPFA();
    output();
    system("pause");
    return 0;
}
