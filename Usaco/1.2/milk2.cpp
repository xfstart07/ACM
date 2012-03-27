/*
ID: xfstart2
LANG: C++
PROG: milk2
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int MAXN=5001;

struct Node{
	int beg,end;
};
int N;
int M1,M2;
Node tim[MAXN];
int cmp(const void *A,const void *B)
{
	Node *ta=(Node *)A;
	Node *tb=(Node *)B;
	return ta->beg - tb->beg;
}
void init()
{
	cin>>N;
	for(int i=1;i<=N;++i)
		cin>>tim[i].beg>>tim[i].end;
	qsort(tim+1,N,sizeof(Node),cmp);
}
void solve()
{
	int i,x,y;
	M1=0; M2=0;
	x=tim[1].beg; y=tim[1].end;
	for(i=2;i<=N;++i)
		if(tim[i].beg > y)
		{
			if(M1 < y-x)
				M1=y-x;
			if(M2 < tim[i].beg-y)
				M2=tim[i].beg-y;
			x=tim[i].beg,y=tim[i].end;
		}
		else if(tim[i].end > y)
			y=tim[i].end;
	if(M1 < y-x)
		M1=y-x;
	cout<<M1<<" "<<M2<<endl;
}
int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	init();
	solve();
	return 0;
}