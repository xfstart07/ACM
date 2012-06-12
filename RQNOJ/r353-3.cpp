/*
NlogN求最长上升，不降子序列
注意二分的打法：就是当c[mid]>=a[i]时也向后面二分，这样就可以将1 1 这种情况
也给存起来。使得有1 1 2 2 3 3这种情况。
*/
#include<cstdio>
using namespace std;

int N;
int Min;
int size;
int a[30010];
int c[30010];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	size=1; c[1]=a[1];
	for(int i=2;i<=N;++i){
		int l=0,r=size;
		while(l<=r){
			int mid=(l+r)>>1;
			if(c[mid]>a[i]) r=mid-1;
			else if(c[mid]<=a[i]) l=mid+1;
		}
		if(l>size) size++;
		c[l]=a[i];
	}
	Min=N-size;
	size=1; c[1]=a[N];
	for(int i=N-1;i>=1;--i){
		int l=0,r=size;
		while(l<=r){
			int mid=(l+r)>>1;
			if(c[mid]>a[i]) r=mid-1;
			else if(c[mid]<=a[i]) l=mid+1;
		}
		if(l>size) size++;
		c[l]=a[i];
	}
	if(Min>N-size) Min=N-size;
	printf("%d\n",Min);
	return 0;
}