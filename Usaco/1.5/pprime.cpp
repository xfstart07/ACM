/*
ID: xfstart2
LANG: C++
PROG: pprime
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int L;
int a,b;
int Ans[1000];
bool check(int d)
{
	for(int i=2;i<=(int)sqrt(d);++i)
		if(d%i==0)
			return 0;
	return 1;
}
int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int i,j,k,t,d;
	L=4;Ans[0]=2;Ans[1]=3;Ans[2]=5;Ans[3]=7;Ans[4]=11;
	for(i=1;i<=9;++i)
		for(j=0;j<=9;++j)
				if(check(d=i*100+j*10+i))
					Ans[++L]=d;
	for(i=1;i<=9;++i)
		for(j=0;j<=9;++j)
			for(k=0;k<=9;++k)
				if(check(d=i*10000+j*1000+k*100+j*10+i))
					Ans[++L]=d;
	for(i=1;i<=9;++i)
		for(j=0;j<=9;++j)
			for(k=0;k<=9;++k)
				for(t=0;t<=9;++t)
					if(check(d=i*1000000+j*100000+k*10000+t*1000+k*100+j*10+i))
						Ans[++L]=d;
	
	
	//cout<<L<<endl;
	scanf("%d%d",&a,&b);
	i=0;
	while(Ans[i]<a) ++i;
	j=i+1;
	while(j<=L && Ans[j]<=b) j++;
	
	for(;i<j;++i)
		printf("%d\n",Ans[i]);
	return 0;
}