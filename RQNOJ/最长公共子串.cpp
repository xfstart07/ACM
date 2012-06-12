#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s1[1005]={0},s2[1005]={0},s[1005]={0};
    gets(s1);
    gets(s2);
    s1[strlen(s1)]='>';
    s2[strlen(s2)]='<';
    for(int i=0;i<strlen(s1);++i)
        for(int j=0;j<strlen(s2);++j)
            if(s1[i]==s2[j]){
                int k=i,p=j,x=1;
                char ch[1005]={0};
                ch[0]=s1[k];
                while(s1[k+1]==s2[p+1]){ k++; p++; ch[x]=s1[k]; x++; }
                if(strlen(ch)>strlen(s))
                    strcpy(s,ch);
            }
    printf("%s\n",s);
    return 0;
}
