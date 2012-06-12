#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int N;
int a[1001];
int f[1001]={0};
int make(int s)
{
	int sum=1,l=sqrt(double(s));
	for(int i=2;i<=l;++i)
		if(s%i==0) sum=sum+i+s/i;
	if(l*l==s) sum-=l;
	return sum;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		a[i]=make(i);
	for(int i=1;i<=N;++i)
		for(int j=N;j>=i;--j)
			if(f[j]<f[j-i]+a[i])
				f[j]=f[j-i]+a[i];
	printf("%d\n",f[N]);
	return 0;
}