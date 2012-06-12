#include<iostream>
using namespace std;

int main()
{
    long n,m,a[10];
    scanf("%d %d",&n,&m);
    memset(a,0,sizeof(a));
    for(long i=n;i<=m;++i){
        char s[20]={0};
        sprintf(s,"%d",i);
        for(long j=0;j<strlen(s);++j)
            a[s[j]-'0']++;
    }
    for(long i=0;i<9;++i) printf("%d ",a[i]);
    printf("%d\n",a[9]);
    return 0;
}
