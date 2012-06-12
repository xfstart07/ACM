#include<cstdio>
#include<cstring>
using namespace std;

int N;
int a[30010];
int f[30010][4];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=3;++i)
		f[0][i]=f[N+1][i]=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=3;++j)
			f[i][j]=0xFFFFFFF;
		for(int j=1;j<=3;++j)
			for(int k=1;k<=j;++k)
				if(f[i][j]>f[i-1][k]+(a[i]!=j))
					f[i][j]=f[i-1][k]+(a[i]!=j);
	}
	int Min=0xFFFFFFF;
	for(int i=1;i<=3;++i)
		if(f[N][i]<Min) Min=f[N][i];
	for(int i=N;i>=1;--i){
		for(int j=1;j<=3;++j)
			f[i][j]=0xFFFFFFF;
		for(int j=1;j<=3;++j)
			for(int k=1;k<=j;++k)
				if(f[i][j]>f[i+1][k]+(a[i]!=j))
					f[i][j]=f[i+1][k]+(a[i]!=j);
	}
	for(int i=1;i<=3;++i)
		if(f[1][i]<Min) Min=f[1][i];
	printf("%d\n",Min);
	return 0;
}