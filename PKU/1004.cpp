/*
 * Problem: POJ 1004
 * Author: Xu Fei
 * Time: 1/10/2011 17:20
 * Solved: AC
 * Method: 模拟
**/
#include<cstdio>
#include<cstring>
using namespace std;

void input()
{
    double a,s=0;
    for (int i=0;i<12;++i)
    {
        scanf("%lf",&a);
        s+=a;
    }
    s/=12.0;
    printf("$%.2lf\n",s);
}
int main()
{
    input();
    return 0;
}