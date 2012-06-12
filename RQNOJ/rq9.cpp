#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct arr{
	int w,d;
}a[60010];
int N,k;
int e[11];
int cmp(const void* A,const void* B)
{
	arr *na=(arr*)A,*nb=(arr*)B;
	if(na->w!=nb->w)
		return nb->w-na->w;
	else return na->d-nb->d;
}
int main()
{
	scanf("%d%d",&N,&k);
	if(k==0) return 0;
	for(int i=1;i<=10;++i)
		scanf("%d",&e[i]);
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i].w);
		a[i].d=i;
	}
	qsort(a+1,N,sizeof(arr),cmp);
	for(int i=1;i<=N;++i)
		a[i].w+=e[(i-1)%10+1];
	qsort(a+1,N,sizeof(arr),cmp);
	if(k>N) k=N;
	for(int i=1;i<k;++i)
		printf("%d ",a[i].d);
	if(k) printf("%d\n",a[k].d);
	else printf("\n");
	return 0;
}