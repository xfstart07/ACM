/*
 * Problem: 基本的Trie
 * Method: 静态构建
 * Author: Xu Fei
 * Time: 24/4/2011
 */
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=10000;

typedef struct Trie{
    int a[27];
};
Trie S[MAX];

int main()
{
    int i,L=0;
    char ch[100];
    for(i=0;i<26;++i) S[0].a[i]=0;
    while(scanf("%s\n",ch)!=EOF)
    {
        int h=0;
        for(i=0;i<(int)strlen(ch);++i)
            if(S[h].a[ch[i]-'A'])
                h=S[h].a[ch[i]-'A'];
            else
            {
                S[h].a[ch[i]-'A']=++L;
                memset(S[L].a,0,sizeof(S[L].a));
                h=L;
            }
    }
    L++;
    printf("%d\n",L);
    return 0;
}
