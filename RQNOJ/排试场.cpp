/*
Ì°ÐÄ
*/
#include<iostream>
using namespace std;

int main()
{
    int n,r,m=0x100,a[10001],sum=0;
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        if(m>a[i]) m=a[i];
        sum+=a[i];
    }
    int ans,re;
    for(int i=m;i>=1;--i)
        if(sum%i==0)
        { ans=(sum-n*i)/i; re=i; break; }
    printf("%d %d\n",ans,re);
    if(re>r) printf("T\n");
    else printf("F\n");
    return 0;
}
