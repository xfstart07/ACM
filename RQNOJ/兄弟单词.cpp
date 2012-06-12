#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,a[26],b[26],ans=0;
    char s[15];
    scanf("%d %s",&n,s);
    memset(a,0,sizeof(a));
    for(int i=0;i<strlen(s);++i) a[s[i]-'a']++;
    for(int i=1;i<=n;++i){
        scanf("%s",s);
        memset(b,0,sizeof(b));
        for(int j=0;j<strlen(s);++j) b[s[j]-'a']++;
        bool bo=1;
        for(int j=0;j<26;++j)
            if(a[j]!=b[j]){ bo=0; break; }
        if(bo) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
