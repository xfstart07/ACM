#include <stdio.h>

int n,a[15],b[6];

void dfs(int dep,int m) {
    if (dep == 6) {
        for (int i=0;i<5;++i)
            printf("%d ",b[i]);
        printf("%d\n",b[5]);
        return;
    }
    for (int i=m;i<=n-6+dep;++i) {
        b[dep]=a[i];
        dfs(dep+1,i+1);
    }
}

int main()
{
    for(scanf("%d",&n);n;) {
        for (int i=0;i<n;++i)
            scanf("%d",a+i);
        dfs(0,0);
        scanf("%d",&n);
        if (n)
            printf("\n");
    }
    return 0;
}
