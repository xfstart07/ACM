/*
ID: xfstart2
LANG: C++
PROG: milk3
*/
#include<fstream>
#include<cstring>
using namespace std;

int A,B,C;
int L,Ans[21];
bool flg[21][21];
inline int min(int a,int b)
{ return a>b?b:a; }
void dfs(int a,int b,int c)
{
	if(flg[a][c]) return;
	flg[a][c]=1;
	//a->b c
	if(a>0)
	{
		dfs(a-min(a,B-b),b+min(a,B-b),c);
		dfs(a-min(a,C-c),b,c+min(a,C-c));
	}
	//b->a c
	if(b>0)
	{
		dfs(a+min(b,A-a),b-min(b,A-a),c);
		dfs(a,b-min(b,C-c),c+min(b,C-c));
	}
	//c->a b
	if(c>0)
	{
		dfs(a+min(c,A-a),b,c-min(c,A-a));
		dfs(a,b+min(c,B-b),c-min(c,B-b));
	}
}
int main()
{
	ifstream cin("milk3.in");
	ofstream cout("milk3.out");
	int i;
	cin>>A>>B>>C;
	memset(flg,0,sizeof(flg));
	dfs(0,0,C);
	L=-1;
	for(i=0;i<=C;++i)
		if(flg[0][i])
			Ans[++L]=i;
	for(int i=0;i<L;++i)
		cout<<Ans[i]<<" ";
	cout<<Ans[L]<<endl;
	return 0;
}