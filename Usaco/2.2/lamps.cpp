/*
ID: xfstart2
LANG: C++
PROG: lamps
*/
#include<cstdio>
#include<cstring>
using namespace std;

int N,C;
int L,Ans[16][101];
int lo,ld,o[101],d[101],a[101];
void init()
{
	scanf("%d%d",&N,&C);
	lo=0; int k;
	do{
		scanf("%d",&k);
		o[++lo]=k;
	}while(k!=-1);
	--lo; ld=0;
	do{
		scanf("%d",&k);
		d[++ld]=k;
	}while(k!=-1);
	--ld;
}
bool equal()
{
	for(int i=1;i<=L;++i){
		bool flg=1;
		for(int j=1;j<=N;++j)
			if(a[j] != Ans[i][j])
			{ flg=0; break; }
		if(flg) return 0;
	}
	return 1;
}
void check(int i1,int i2,int i3,int i4)
{
	if(i1+i2+i3+i4>C) return;
	if(i1)
		for(int i=1;i<=N;++i)
			a[i]=0;
	else
		for(int i=1;i<=N;++i)
			a[i]=1;
	if(i2)
		for(int i=1;i<=N;++i)
			if(i&1)
				a[i]=1-a[i];
	if(i3)
		for(int i=1;i<=N;++i)
			if(i&1 == 0)
				a[i]=1-a[i];
	if(i4)
		for(int i=1;i<=N;i+=3)
			a[i]=1-a[i];
	for(int i=1;i<=lo;++i)
		if(!a[o[i]])
			return;
	for(int i=1;i<=ld;++i)
		if(a[d[i]])
			return;
	if(L==0 || equal()){
		L++;
		memcpy(Ans[L],a,sizeof(a));
	}
}
bool f(int x,int y)
{
	for(int i=1;i<=N;++i)
		if(Ans[x][i] > Ans[y][i])
			return 1;
		else if(Ans[x][i] < Ans[y][i])
			return 0;
	return 0;
}
void swap(int x,int y)
{
	for(int i=1;i<=N;++i) a[i]=Ans[x][i];
	for(int i=1;i<=N;++i) Ans[x][i]=Ans[y][i];
	for(int i=1;i<=N;++i) Ans[y][i]=a[i];
}
void solve()
{
	L=0;
	for(int i1=0;i1<=1;++i1)
		for(int i2=0;i2<=1;++i2)
			for(int i3=0;i3<=1;++i3)
				for(int i4=0;i4<=1;++i4)
					check(i1,i2,i3,i4);
	if(L == 0) printf("IMPOSSIBLE\n");
	for(int i=1;i<L;++i)
		for(int j=i+1;j<=L;++j)
			if(f(i,j))
				swap(i,j);
	for(int i=1;i<=L;++i)
	{
		for(int j=1;j<=N;++j)
			printf("%d",Ans[i][j]);
		printf("\n");
	}
}
int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	init();
	solve();
	return 0;
}