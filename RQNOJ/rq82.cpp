#include<cstdio>
#include<cstring>
using namespace std;

int N;
int a[10010];
int f[10010][2];
int min(int x,int y)
{ return x>y?y:x; }
int main()
{
	scanf("%d",&N);
	if(N>=1){ scanf("%d",&a[1]); f[1][0]=a[1]; f[1][1]=0; }
	if(N>=2){
		scanf("%d",&a[2]);
		f[2][0]=f[1][1]+a[2]; 
		f[2][1]=0;
	}
	for(int i=3;i<=N;++i){
		scanf("%d",&a[i]);
		f[i][0]=min(f[i-1][0],f[i-1][1])+a[i];  //仔细体会，f[i][0]有可以从i-1连续走，也有可以跳过f[i-1][1]，
		//但是不可能跳过f[i-2][1]，因为当f[i-2][1]是跳第二层时则，相当于跳了三层了。这点很难想到，仔细体会一下。
		//如果跳二层更优的话，那么f[i-1][1]就会选择跳二层的最优值，所以不会有漏掉的情况。
		f[i][1]=min(f[i-1][0],f[i-2][0]);  //仔细体会 ，f[i][1]有可能是跳第一层，也有可能是跳第二层
	}
	printf("%d\n",min(f[N][0],f[N][1]));
	return 0;
}