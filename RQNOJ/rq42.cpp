#include<cstdio>
#include<cstring>
using namespace std;

int N,k;
int a[5010];
int f[5010];
int max(int x,int y)
{ return x>y?x:y; }
int main()
{
	scanf("%d%d",&N,&k);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	f[1]=1;
	for(int i=2;i<=N;++i){
		f[i]=0xFFFFFFF; double Min=0xFFFFFFF;
		for(int j=i-1;j>=max(1,i-k);--j){
			double k=(double)(a[i]-a[j])/(double)(i-j);
			if(Min>k) Min=k;
			if(k<=Min)
				if(f[i]>f[j]+1)
					f[i]=f[j]+1;
		}
	}
	printf("%d\n",f[N]);
	return 0;
}