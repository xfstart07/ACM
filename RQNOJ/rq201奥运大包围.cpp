/*
LISģ��+ö��

һ����Ŀ�Ӹߵ��ͣ��������뵽����LIS��û����Ŀ�����ص����ڶ�����ࡣ������ĿҪ��Ӹߵ��ͣ���ô��������������С���Ϊ˳��Ҫ�Ӹߵ���˳����ô�����������������е�Ԫ��һ��������ԭȦ��������ЩԪ��һ�����Լ���Ȧ����������������е�Ԫ�ؼ�Ϊ����Ҫ�γɶ��ٸ�������Ȧ��������ö�ٴ��Ǹ�λ�öϿ���LIS���ҳ�һ����С�ļ��ɡ�
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