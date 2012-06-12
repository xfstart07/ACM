#include<cstdio>
#include<cstring>
using namespace std;

typedef int Arr[100];
int N;
Arr f[62][62][62];
void add(Arr &a,Arr b)
{
	if(a[0]<b[0]) a[0]=b[0];
	for(int i=1;i<=a[0];++i)
		a[i]+=b[i];
	for(int i=1;i<=a[0];++i){
		a[i+1]+=a[i]/1000000000;
		a[i]%=1000000000;
	}
	while(a[a[0]+1]){
		a[0]++;
		a[a[0]+1]+=a[a[0]]/1000000000;
		a[a[0]]%=1000000000;
	}
}
int main()
{
	scanf("%d",&N);
	//memset(f,0,sizeof(f));
	f[0][0][0][0]=1;
	f[0][0][0][1]=1;
	for(int i=0;i<=N;++i)
		for(int j=0;j<=N;++j)
			for(int k=0;k<=N;++k) if(i>=j&&j>=k){
				if(i-1>=0) add(f[i][j][k],f[i-1][j][k]);
				if(j-1>=0) add(f[i][j][k],f[i][j-1][k]);
				if(k-1>=0) add(f[i][j][k],f[i][j][k-1]);
			}
			else f[i][j][k][0]=1;
	int len=f[N][N][N][0];
	printf("%d",f[N][N][N][len]);
	for(int i=len-1;i>=1;--i)
		printf("%09d",f[N][N][N][i]);
	printf("\n");
	return 0;
}