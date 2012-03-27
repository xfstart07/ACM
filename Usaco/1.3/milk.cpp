/*
ID: xfstart2
LANG: C++
PROG: milk
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct Node{
	int p,a;
};
int N,M,Ans;
Node Pa[5001];
int cmp(const void* A,const void* B)
{
	Node *ta=(Node *)A;
	Node *tb=(Node *)B;
	return ta->p - tb->p;
}
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int i;
	cin>>N>>M;
	for(i=0;i<M;++i)
		cin>>Pa[i].p>>Pa[i].a;
	qsort(Pa,M,sizeof(Node),cmp);
	Ans=0;
	for(i=0;i<M;++i)
	{
		if(N>Pa[i].a)
			Ans+=Pa[i].p*Pa[i].a,N-=Pa[i].a;
		else Ans+=Pa[i].p*N,N=0;
	}
	cout<<Ans<<endl;
	return 0;
}