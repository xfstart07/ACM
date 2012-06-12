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
	for(int i=2;i<=N;++i){
		for(int j=i-1;j>=1;--j)
			if(check(i,j))
				if(f[i]<f[j]+1)
					f[i]=f[j]+1;
		if(Ans<f[i]) Ans=f[i];
	}
	printf("%d\n",Ans);
	return 0;
}