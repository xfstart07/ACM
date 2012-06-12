/*
LIS模型+枚举

一看题目从高到低，很容易想到就是LIS，没错题目和拦截导弹第二个差不多。由于题目要求从高到低，那么就求最长上升子序列。因为顺序要从高到低顺序，那么求出来的最长上升子序列的元素一定不会在原圈，而且这些元素一定是自己分圈，所以最长上升子序列的元素即为最少要形成多少个这样的圈。最后就是枚举从那个位置断开求LIS，找出一个最小的即可。
*/


#include<iostream>
using namespace std;

int n;
int a[1010];
int c[1010];
int b[1010];
int f[1010];
int size;
int bsearch(int ai){
	int l=1,r=size;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ai>=c[mid-1]&&ai<c[mid]) return mid;
		else if(ai>=c[mid]) l=mid+1;
		else r=mid-1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int Max=0x7FFFFFFF;
	for(int i=1;i<=n;++i){
		int l=0;
		for(int j=i;j<=n;++j){
			b[++l]=a[j];
			f[l]=1;
		}
		for(int j=1;j<i;++j){
			b[++l]=a[j];
			f[l]=1;
		}
		c[1]=b[1]; size=1;
		for(int j=2;j<=n;++j){
			int k;
			if(b[j]<c[1]) k=1;
			else if(b[j]>=c[size]) k=++size;
			else k=bsearch(b[j]);
			c[k]=b[j];
		}
		if(Max>size)
			Max=size;
	}
	printf("%d\n",Max);
	return 0;
}