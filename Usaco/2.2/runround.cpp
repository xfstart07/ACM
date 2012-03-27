/*
ID: xfstart2
LANG: C++
PROG: runround
*/
#include<cstdio>
#include<cstring>
using namespace std;

int l,a[10];
int b[10];
bool check()
{
	memset(b,0,sizeof(b));
	int i=1;
	do{
		b[i]++;
		if(b[i]>1) break;
		i=(i+a[i])%l;
		if(i==0) i=l;
	}while(i!=1);
	for(int i=1;i<=l;++i)
		if(b[i]==0 || b[i]>1)
			return 0;
	return 1;
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(n++;;++n)
	{
		int k=n; l=0;
		memset(b,0,sizeof(b));
		while(k){
			b[a[++l]=k%10]++;
			k/=10;
		}
		if(b[0]) continue;
		bool flg=0;
		for(int i=1;i<=9;++i)
			if(b[i]>1){
				flg=1; break;
			}
		if(flg) continue;
		for(int i=1;i<=l/2;++i)
		{
			int tmp=a[i]; a[i]=a[l-i+1]; a[l-i+1]=tmp;
		}
		if(check()) break;
	}
	printf("%d\n",n);
	return 0;
}