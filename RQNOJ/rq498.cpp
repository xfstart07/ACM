#include<iostream>
#include<cstdio>
using namespace std;

typedef int Arr[100005];
int N;
int Ans;
Arr a,b,ind,arr,brr;
int cmp(int x,int y)
{
	return (a[x]<a[y]||a[x]==a[y]&&b[x]<b[y]);
}
void init()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<N;++i)
		ind[i]=i;
	sort(ind,ind+N,cmp);
}
int min2(int ai,int size)
{
	int l=1,r=size;
	while(l<=r){
		int mid=(l+r)>>1;
		if(brr[mid-1]<ai&&brr[mid]>=ai) return mid;
		else if(brr[mid]>ai) r=mid-1;
		else l=mid+1;
	}
}
int LIS(int n)
{
	if(n==0) return 0;
	int size=1;
	brr[1]=arr[0];
	for(int i=1,j;i<n;++i){
		if(brr[1]>=arr[i])
			j=1;
		else if(brr[size]<arr[i])
			j=++size;
		else{
			int l=1,r=size; j=0;
			while(l<r){
				int mid=(l+r)>>1;
				if(brr[mid]<arr[i])
					j=l=mid+1;
				else r=mid-1;
			}
		}
		brr[j]=arr[i];
	}
	return size;
}
void solve()
{
	Ans=0;
	for(int i=0;i<N;++i){
		int k=ind[i];
		int q=0;
		for(int j=i+1;j<N&&a[ind[j]]<b[k];++j)
			if(b[ind[j]]>b[k])
				arr[q++]=b[ind[j]];
		int p=LIS(q)+1;
		if(Ans<p)
			Ans=p;
	}
	printf("%d\n",Ans);
}
int main()
{
	init();
	solve();
	return 0;
}
