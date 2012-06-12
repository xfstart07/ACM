#include<iostream>
#include<cstring>
using namespace std;

int find(char *s,char *ch){
    for(int i=0;i<strlen(s);++i)
        if(s[i]==ch[0]) return i;
}
int main()
{
    char s[26]={0},ch[2]={0};
    int n,p;
    gets(s);
    puts(s);
    scanf("%d\n",&n);
    for(int i=0;i<n;++i){
        gets(ch);
        p=find(s,ch);
        char s1[26]={0},s2[26]={0};
        strncpy(s1,s,p);
        strncpy(s2,s+p+1,strlen(s)-p);
        if(strlen(s1)<=strlen(s2)) strrev(s1);
        else strrev(s2);
        strcat(s1,s2);
        strcpy(s,s1);
        puts(s);
    }
    return 0;
}
