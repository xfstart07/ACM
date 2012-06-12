#include<cstdio>
#include<cstring>
using namespace std;

struct arr{
	int h,t,c;
}f[110][110];
int N;
int main()
{
	scanf("%d%d",&N,&f[1][1].h);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) 
			f[i][j].c=0;
	for(int i=2;i<=N;++i){
		scanf("%d",&f[i][i].h);
		f[i-1][i-1].t=f[i][i].h;
	}
	f[N][N].t=f[1][1].h;
	for(int k=2;k<=N;++k){
		for(int i=1;i<=N;++i){
			int j=(i+k-1-1)%N+1;  
			for(int t=i;t<i+k-1;++t){
				int t1=(t-1)%N+1,t2=(t+1-1)%N+1;
				if(f[i][j].c<f[i][t1].c+f[t2][j].c+f[i][t1].h*f[i][t1].t*f[t2][j].t)
					f[i][j].c=f[i][t1].c+f[t2][j].c+f[i][t1].h*f[i][t1].t*f[t2][j].t;
			}
			f[i][j].h=f[i][i].h;
			f[i][j].t=f[j][j].t;
		}
	}
	int Ans=0;
	for(int i=1;i<=N;++i){
		int j=(i+N-1-1)%N+1;
		if(f[i][j].c>Ans)
			Ans=f[i][j].c;
	}
	printf("%d\n",Ans);
	return 0;
}