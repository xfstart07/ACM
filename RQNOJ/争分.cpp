#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct arr{
    char s1[215],s2[115];
};
arr s[5001];
int cmp(const void *no1,const void *no2){
    arr *nox=(arr *)no1,*noy=(arr *)no2;
    if(strlen(nox->s2)>strlen(noy->s2)) return -1;
    else if(strlen(nox->s2)<strlen(noy->s2)) return 1;
    else{
        for(int i=0;i<strlen(nox->s2);++i)
            if(nox->s2[i]>noy->s2[i]) return -1;
        else
            if(nox->s2[i]<noy->s2[i]) return 1;
        return strcmp(nox->s1,noy->s1);
    }
}
int main()
{
    long n;
    scanf("%d",&n);
    getchar();
    for(long i=0;i<n;++i){
        gets(s[i].s1);
        gets(s[i].s2);
        while(s[i].s2[0]=='0'){
            strncpy(s[i].s2,s[i].s2+1,strlen(s[i].s2)-1);
            s[i].s2[strlen(s[i].s2)-1]='\0';
        }
    }
    qsort(s,n,sizeof(arr),cmp);
    for(long i=0;i<n;++i) puts(s[i].s1);
    return 0;
}
