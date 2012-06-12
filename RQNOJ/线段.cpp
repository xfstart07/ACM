#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double x1,y1,r1,x2,y2,r2,rr;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
    rr=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    rr=rr*2.0;
    printf("%0.6lf\n",rr);
    return 0;
}
