#include<cstdio>
#include<cstring>
using namespace std;

int N;
int len,Ans;
char s[100];
int t[100010][26];
int f[100010];
int main()
{
	scanf("%d",&N);
	memset(t,0,sizeof(t));
	memset(f,0,sizeof(f));
	Ans=0; len=0;
	for(int i=1;i<=N;++i){
		scanf("%s",s);
		int tmp=1,c=0,l=strlen(s);
		for(int j=0;j<l;++j)
			if(t[c][s[j]-'a']==0){
				len++;
				t[c][s[j]-'a']=len;
				c=len;
			}
			else{
				c=t[c][s[j]-'a'];
				if(f[c]) tmp++;
			}
		f[c]=1;
		if(tmp>Ans) Ans=tmp;
	}
	printf("%d\n",Ans);
	return 0;
}

/*
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef char string[75];
int N;
int Ans;
int f[10010];
int l[10010];
string s[10010];
bool check(int x,int y)
{
if(l[y]>l[x]) return 0;
for(int i=0;i<l[y];++i)
if(s[x][i]!=s[y][i])
return 0;
return 1;
}
int main()
{
scanf("%d",&N);
for(int i=1;i<=N;++i){
scanf("%s",s[i]);
f[i]=1; l[i]=strlen(s[i]);
}
Ans=1;
for(int i=1;i<=N;++i){
int tmp=1;
for(int j=i-1;j>=1;--j){
if(check(i,j)){
tmp=f[j]+1;
break;                  //想想问什么这里可以跳呢
}
if(s[i][0]!=s[j][0]) break;   //想想问什么这里可以跳呢
}
f[i]=tmp;
if(Ans<f[i]) Ans=f[i];
}
printf("%d\n",Ans);
return 0;
}
*/