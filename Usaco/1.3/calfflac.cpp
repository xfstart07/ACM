/*
ID: xfstart2
LANG: C++
PROG: calfflac
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

int L,Ans;
int Ax,Ay;
char S[20001];
void init()
{
	L=-1;
	char ch;
	while((ch=getchar())!=EOF)
		S[++L]=ch;
}
bool check(char c)
{
	if(c>='A'&&c<='Z' || c>='a'&&c<='z')
		return 1;
	return 0;
}
void equal(int &x,int &y,int &p)
{
	int x1=x-1,y1=y+1;
	while(x1>=0&&y1<=L)
	{
		while(x1>=0&&!check(S[x1])) --x1;
		while(y1<=L&&!check(S[y1])) ++y1;
		if(x1<0 || y1>L || tolower(S[x1]) != tolower(S[y1])) return;
		x=x1; y=y1; p+=2;
		x1=x-1; y1=y+1;
	}
}
void solve()
{
	int i,x,y,P;
	Ans=0;
	for(i=0;i<=L;++i)
		if(check(S[i]))
		{
			x=y=i; P=1;
			equal(x,y,P);
			if(P > Ans)
				Ax=x,Ay=y,Ans=P;
		}
	for(i=0;i<=L;++i)
		if(check(S[i]))
		{
			x=i; y=i+1;
			while(y<=L && !check(S[y])) ++y;
			if(y>L || tolower(S[x]) != tolower(S[y])) continue;
			P=2;
			equal(x,y,P);
			if(P > Ans)
				Ax=x,Ay=y,Ans=P;
		}
	printf("%d\n",Ans);
	for(i=Ax;i<=Ay;++i)
		printf("%c",S[i]);
	printf("\n");
}
int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	init();
	solve();
	return 0;
}