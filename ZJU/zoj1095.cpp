#include <cstdio>

int min(int a,int b)
{ return a>b?b:a; }
int main()
{
    int a[5850];
    a[1]=1;
    int p2,p3,p5,p7;
    p2=p3=p5=p7=1;
    for (int i=2;i<=5842;++i) {
        int m = min(min(2*a[p2],3*a[p3]),min(5*a[p5],7*a[p7]));
        a[i] = m;
        //printf("%d %d %d %d\n",2*a[p2],3*a[p3],5*a[p5],7*a[p7]);
        if (m == 2*a[p2]) p2++;
        if (m == 3*a[p3]) p3++;
        if (m == 5*a[p5]) p5++;
        if (m == 7*a[p7]) p7++;
    }

    int n;
    while (scanf("%d",&n) != EOF) {
        if (n == 0) break;
        
        int tmp = n/10%10;
        printf("The %d",n);
        if (n%10 == 1 && tmp != 1) printf("st");
        else if (n%10 == 2 && tmp != 1) printf("nd");
        else if (n%10 == 3 && tmp != 1) printf("rd");
        else printf("th");
        printf(" humble number is %d.\n",a[n]);
    }
    return 0;
}
