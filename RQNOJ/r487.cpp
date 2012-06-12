#include<cstdio>
using namespace std;

int N,M;
__int64 f[35][35];
int main()
{
	scanf("%d%d",&N,&M);
	f[1][0]=1;
	for(int j=1;j<=M;++j){
		for(int i=1;i<=N;++i)
			f[i][j]+=f[(i-1+N-1)%N+1][j-1]+f[i%N+1][j-1];
	}
	printf("%I64d\n",f[1][M]);
	return 0;
}