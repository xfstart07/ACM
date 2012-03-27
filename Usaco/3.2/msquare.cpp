/*
ID: xfstart2
LANG: C++
PROG: msquare
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

struct Node{
	int prev;
	int col;
	int count;
	int A[9];
};
int H,T,L;
int Ed[9];
int Bit[9];
string Ans;
bool hash[40321];
Node que[40321];

void input()
{
	int i;
	for(i=1;i<=8;++i)
		cin>>Ed[i];
	
	H=T=1;
	que[1].prev=1;
	que[1].col=que[1].count=0;
	for(i=1;i<=8;++i)
		que[1].A[i]=i;
	
	memset(hash,true,sizeof(hash));
	Bit[0]=1;
	for(i=1;i<=8;++i)
		Bit[i]=Bit[i-1]*i;
}
bool equal(int n)
{
	int i;
	for(i=1;i<=8;++i)
		if(que[n].A[i] != Ed[i])
			return false;
	return true;
}
int HASH(int n)
{
	int i,j,k,s;
	bool b[9];
	s=0;
	memset(b,true,sizeof(b));
	for(i=1;i<=8;++i)
	{
		b[k=que[n].A[i]]=false;
		k--;
		for(j=1;j<que[n].A[i];++j)
			if(!b[j]) k--;
		s+=k*Bit[8-i];
	}
	return s+1;
}
bool check(int col)
{
	int i;
	Node tmp;
	switch(col){
		case 0:
			for(i=1;i<=8;++i)
				tmp.A[i]=que[H].A[8-i+1];
		break;
		case 1:
			for(i=2;i<=4;++i)
				tmp.A[i]=que[H].A[i-1];
			for(i=5;i<=7;++i)
				tmp.A[i]=que[H].A[i+1];
			tmp.A[1]=que[H].A[4];
			tmp.A[8]=que[H].A[5];
		break;
		case 2:
			for(i=1;i<=8;++i)
				tmp.A[i]=que[H].A[i];
			tmp.A[2]=que[H].A[7];
			tmp.A[3]=que[H].A[2];
			tmp.A[6]=que[H].A[3];
			tmp.A[7]=que[H].A[6];
		break;
	}
	tmp.col=col;
	tmp.prev=H;
	tmp.count=que[H].count+1;
	que[++T]=tmp;
	int h=HASH(T);
	if(!hash[h])
	{
		--T;
		return false;
	}
	hash[h]=false;
	return equal(T);
}
void solve()
{
	if(equal(1)) return;
	int h=HASH(1);
	hash[h]=false;
	while(H<=T)
	{
		if(check(0)) return;
		if(check(1)) return;
		if(check(2)) return;
		H++;
	}
}
void dfs(int n)
{
	if(que[n].prev != n)
	{
		dfs(que[n].prev);
		Ans=Ans+char(que[n].col+'A');
	}
}
void output()
{
	int i;
	Ans="";
	L=que[T].count;
	
	dfs(T);
	
	cout<<L<<endl;
	for(i=1;i<L;++i)
		if(i%60 == 0)
			cout<<Ans[i-1]<<endl;
		else
			cout<<Ans[i-1];
	if(L)
		cout<<Ans[L-1]<<endl;
	else
		cout<<endl;
}
int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	
	input();
	solve();
	output();
	return 0;
}