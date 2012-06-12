#include<iostream>
using namespace std;

int main()
{
    int n,p,k;
    cin>>n;
    p=(n/5)+(n/25)+(n/125)+(n/625)+(n/3125)+(n/15625)+(n/78125)+(n/390625)+(n/1953125);
    k=1;
    for(int i=2;i<=n;++i){
        int x=i;
        while(x%5==0) x/=5;
        if(p&&x%2==0){
            --p;
            x/=2;
        }
        k*=x;
        k%=10;
    }
    cout<<k<<endl;
    return 0;
}
