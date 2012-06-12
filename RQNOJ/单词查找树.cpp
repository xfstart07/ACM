#include<iostream>
#include<cstring>
using namespace std;

struct arr{
    int a[26];
}s[500000];
int main()
{
    int l=0;
    char ch[70]={0};
    for(int i=0;i<26;++i) s[0].a[i]=0;
    while(scanf("%s\n",ch)!=EOF){
        int h=0;
        for(int i=0;i<strlen(ch);++i)
            if(s[h].a[ch[i]-'A']) h=s[h].a[ch[i]-'A'];
            else{
                s[h].a[ch[i]-'A']=++l;
                for(int i=0;i<26;++i) s[l].a[i]=0;
                h=l;
            }
    }
    l++;
    printf("%d\n",l);
    return 0;
}
