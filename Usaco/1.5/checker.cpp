/*
ID: xfstart2
LANG: C++
PROG: checker
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int N;
int tot,res,Ans[2][15];
bool row[30],l[30],r[30];
void dfs(int i)
{
	if(i > N)
	{
		tot++;
		memcpy(Ans[1],Ans[0],sizeof(Ans[0]));
		if(tot<4){
			for(int j=1;j<N;++j)
				cout<<Ans[0][j]<<" ";
			cout<<Ans[0][N]<<endl;
		}
		if(N&1 && Ans[0][N] == (int)(N+1)/2) res++;
	}
	for(int j=1;j<=N;++j)
		if(row[j] && l[i+j] && r[i-j+N])
		{
			row[j]=l[i+j]=r[i-j+N]=0;
			Ans[0][i]=j;
			dfs(i+1);
			row[j]=l[i+j]=r[i-j+N]=1;
		}
}
int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	cin>>N;
	memset(row,1,sizeof(row));
	memset(l,1,sizeof(l));
	memset(r,1,sizeof(r));
	tot=res=0;
	for(int i=1;i<=(int)N/2;++i)
		if(row[i] && l[i+1] && r[1-i+N])
		{
			row[i]=l[i+1]=r[1-i+N]=0;
			Ans[0][1]=i;
			dfs(2);
			row[i]=l[i+1]=r[1-i+N]=1;
		}
	if(N == 6)
	{
		for(int i=1;i<N;++i)
			cout<<N+1-Ans[1][i]<<" ";
		cout<<N+1-Ans[1][N]<<endl;
	}
	cout<<(tot+res)*2<<endl;
	return 0;
}