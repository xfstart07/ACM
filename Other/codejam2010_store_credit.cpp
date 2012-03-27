#include <stdio.h>

int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int ni=1;ni<=n;++ni) {
        int c,l,a[2002];
        scanf("%d%d",&c,&l);
        for (int i=1;i<=l;++i)
            scanf("%d",a+i);
	a[0] = 0;
        int x = 0,y = 0;
        for (int i=1;i<l;++i) {
            for (int j=i+1;j<=l;++j)
                if (a[i] + a[j] <= c && a[x] + a[y] < a[i] + a[j])
                    x=i,y=j;
        }
        printf("Case #%d: %d %d\n",ni,x,y);
    }
    return 0;
}
