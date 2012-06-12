#include<cstdio>
#include<cstring>
using namespace std;

int N,M;
int f[110][110];
int a[110][110];
int min(int x,int y,int z){
	if(x>y) x=y; if(x>z) x=z;
	return x;
}
int main()
{
	scanf("%d%d",&N,&M); getchar();
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			char ch; scanf("%c",&ch);
			a[i][j]=ch-'0';
		}
		getchar();
	}
	memset(f,0x7F,sizeof(f));
	memset(a[0],0,sizeof(a[0]));
	int dep=1;
	for(int i=1;i<=M;++i) f[N+1][i]=0;
	for(int i=N;i>=N/2+1;--i){
		for(int j=1;j<=M;++j){
			f[i][j]=min(f[i+1][j-1]+a[i-dep][j],f[i+1][j]+a[i-dep+1][j]+a[i-dep][j],f[i+1][j+1]+a[i-dep][j]);
		}
		dep++;
	}
	int Ans=0xFFFFFFF;
	for(int i=1;i<=M;++i)
		if(f[N/2+1][i]<Ans)
			Ans=f[N/2+1][i];
	printf("%d\n",Ans);
	return 0;
}