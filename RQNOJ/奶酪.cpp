#include<iostream>
#define min(a,b)(a>b?b:a)
using namespace std;

int main()
{
    int a,b,c,d,e=0,k;
    cin>>a>>b>>c>>d;
    k=min(a,d);
    a-=k; d-=k; e+=k;
    k=min(b,c);
    b-=k; c-=k; e+=k;
    k=min(a/2,c);
    a-=k*2; c-=k; e+=k;
    k=min(a,b/2);
    a-=k; b-=k*2; e+=k;
    k=min(a/3,b);
    a-=k*3; b-=k; e+=k;
    e+=a/5;
    cout<<e<<endl;
    return 0;
}
/*
贪心顺序：
1 4
2 3
1 1 3
1 2 2
1 1 1 2
1 1 1 1 1

数据：
74 23 25 53
答案是：81
*/
