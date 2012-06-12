#include<cstdio>
using namespace std;

typedef int Arr[210][210];
int N;
Arr M1,M2,S1,S2;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		int a; scanf("%d",&a);
		M1[i][i]=M2[i][i]=M1[i+N][i+N]=M2[i+N][i+N]=a;
		S1[i][i]=S2[i][i]=S1[i+N][i+N]=S2[i+N][i+N]=0;
	}
	for(int k=2;k<=N;++k){
		for(int i=1;i<=2*N-k+1;++i){
			int j=i+k-1;
			M1[i][j]=S1[i][j]=0xFFFFFFF;
			M2[i][j]=S2[i][j]=0;
			for(int t=j-1;t>=i;--t){
				if(M1[i][j]>M1[i][t]+M1[t+1][j]){
					M1[i][j]=M1[i][t]+M1[t+1][j];
					if(S1[i][j]>M1[i][j]+S1[i][t]+S1[t+1][j])
						S1[i][j]=M1[i][j]+S1[i][t]+S1[t+1][j];
				}
				else if(M1[i][j]==M1[i][t]+M1[t+1][j]){
					if(S1[i][j]>M1[i][j]+S1[i][t]+S1[t+1][j])
						S1[i][j]=M1[i][j]+S1[i][t]+S1[t+1][j];
				}
				if(M2[i][j]<=M2[i][t]+M2[t+1][j]){
					M2[i][j]=M2[i][t]+M2[t+1][j];
					if(S2[i][j]<M2[i][j]+S2[i][t]+S2[t+1][j])
						S2[i][j]=M2[i][j]+S2[i][t]+S2[t+1][j];
				}
				else if(M2[i][j]==M2[i][t]+M2[t+1][j]){
					if(S2[i][j]<M2[i][j]+S2[i][t]+S2[t+1][j])
						S2[i][j]=M2[i][j]+S2[i][t]+S2[t+1][j];
				}
			}
		}
	}
	int ans=0xFFFFFFF;
	for(int i=1;i<=N;++i)
		if(S1[i][i+N-1]<ans)
			ans=S1[i][i+N-1];
	printf("%d\n",ans);
	ans=0;
	for(int i=1;i<=N;++i)
		if(S2[i][i+N-1]>ans)
			ans=S2[i][i+N-1];
	printf("%d\n",ans);
	return 0;
}