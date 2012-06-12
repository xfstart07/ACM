#include<cstdio>
#include<cstring>
using namespace std;

int N;
int Ans;
int a[110];
int b[110];
int c[110];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=N;++i){
		b[i]=1;
		for(int j=1;j<i;++j)
			if(a[j]<a[i]&&b[i]<b[j]+1)
				b[i]=b[j]+1;
	}
	for(int i=N;i>=1;--i){
		c[i]=1;
		for(int j=i+1;j<=N;++j)
			if(a[j]<a[i]&&c[i]<c[j]+1)
				c[i]=c[j]+1;
	}
	Ans=0;
	for(int i=1;i<=N;++i)
		if(b[i]+c[i]-1>Ans)
			Ans=b[i]+c[i]-1;
	printf("%d\n",N-Ans);
	return 0;
}