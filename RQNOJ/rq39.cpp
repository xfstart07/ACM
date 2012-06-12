#include<cstdio>
#include<cstring>
using namespace std;

int N,M;
int f[35100];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;++i){
		int a; scanf("%d",&a);
		for(int j=N;j>=a;--j)
			if(f[j]<f[j-a]+a)
				f[j]=f[j-a]+a;
	}
	printf("%d\n",f[N]);
	return 0;
}