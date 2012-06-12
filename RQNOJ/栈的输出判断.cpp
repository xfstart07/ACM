#include<iostream>
using namespace std;

int n,a[5001],b[5001],m,l;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    m=n; l=0;
    for(int i=n;i>=1;--i){
        b[++l]=a[i];
        while(l&&b[l]==m){
            l--;
            m--;
        }
    }
    bool bk=0;
    while(l){
        if(b[l]==m){
            l--;
            m--;
        }
        else{
            bk=1; break;
        }
    }
    if(bk) printf("Wrong\n");
    else printf("Right\n");
    return 0;
}
