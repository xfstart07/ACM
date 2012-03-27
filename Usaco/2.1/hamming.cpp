/*
ID: xfstart2
LANG: C++
PROG: hamming
*/
#include<cstdio>
#include<cstring>
using namespace std;

int N,B,D,L;
int a[65][10],b[10];
int Ans[65];

int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&N,&B,&D);
	L=1; Ans[1]=0;
	for(int i=1;i<=B;++i)
		a[L][i]=0;
	for(int i=1;i<=1<<B;++i)
	{
		int k=i,l=0;
		for(int j=1;j<=B;++j) b[j]=0;
		while(k){
			b[++l]=k%2;
			k/=2;
		}
		bool flg=1;
		for(int j=1;j<=L;++j)
		{
			int d=0;
			for(int p=1;p<=B;++p)
				if(a[j][p] != b[p])
					d++;
			if(d<D)
			{
				flg=0; break;
			}
		}
		if(flg)
		{
			Ans[++L]=i;
			memcpy(a[L],b,sizeof(b));
		}
		if(L == N) break;
	}
	for(int i=1;i<L;++i)
		if(i%10==0)
			printf("%d\n",Ans[i]);
		else 
			printf("%d ",Ans[i]);
	printf("%d\n",Ans[L]);
	return 0;
}