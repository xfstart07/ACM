#include<iostream>
#include<cmath>
using namespace std;

bool check(long s){
    for(int i=2;i<=(int)sqrt(s);++i)
        if(s%i==0) return 0;
    return 1;
}
int main()
{
    int n,k,MAX,MIN,a;
    scanf("%d %d",&n,&k);
    MAX=0; MIN=0xFFFFFFF;
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(k>a){
            if(a>MAX) MAX=a;
        }
        else if(k<a){
            if(MIN>a) MIN=a;
        }
    }
    printf("%d\n",MIN+MAX);
    if(check(MIN+MAX)) printf("Y\n");
    else printf("F\n");
    return 0;
}
