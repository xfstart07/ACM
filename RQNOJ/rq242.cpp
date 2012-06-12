#include<iostream>
using namespace std;

int n;
int a[100010];
int b[100010];
int c[100010];
int size;
int cal(int ai){
	int l=1,r=size;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ai>c[mid-1]&&ai<=c[mid]) return mid;
		else if(ai<c[mid]) r=mid-1;
		else l=mid+1;
	}
}
int main()
{
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		a[x]=i;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		b[a[x]]=i;
	}
	c[1]=b[1]; size=1;
	for(int i=2;i<=n;++i){
		int j;
		if(b[i]<c[1]) j=1;
		else if(b[i]>c[size]) j=++size;
		else j=cal(b[i]);
		c[j]=b[i];
	}
	printf("%d\n",n-size);
	return 0;
}