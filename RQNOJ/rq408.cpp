#include<cstdio>
#include<cstring>
using namespace std;

int N,M,p;
int a[210];
int b[210];
int s[210][210];
void init()
{
	scanf("%d%d\n",&N,&M);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			char ch; ch=getchar();
			s[i][j]=ch-'0';
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
		getchar();
	}
	scanf("%d",&p);
	for(int i=1;i<=p;++i)
		scanf("%d",&a[i]);
}
void solve()
{
	int l;
	if(N>M) l=M;
	else l=N;
	memset(b,0,sizeof(b));
	for(int k=1;k<=l;++k)
		for(int i=k;i<=N;++i)
			for(int j=k;j<=M;++j)
				if(s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k]==k*k)
					b[k]++;
	for(int i=1;i<=p;++i)
		printf("%d\n",b[a[i]]);
}
int main()
{
	init();
	solve();
	return 0;
}