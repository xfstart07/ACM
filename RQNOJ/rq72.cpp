#include<cstdio>
#include<cstring>
using namespace std;

int N;
int a[110];
int f[5100];
int main()
{
	scanf("%d",&N); int sum=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	} int s=sum;
	sum/=2;
	for(int i=1;i<=N;++i){
		for(int j=sum;j>=a[i];--j)
			if(f[j]<f[j-a[i]]+a[i])
				f[j]=f[j-a[i]]+a[i];
	}
	printf("%d\n",s-f[sum]*2);
	return 0;
}