/*
ID: xfstart2
LANG: C++
PROG: sprime
*/
#include<cstdio>
#include<cmath>
using namespace std;

int N;
bool check(int s)
{
	for(int i=2;i<=(int)sqrt(s);++i)
		if(s%i==0)
			return 0;
	return 1;
}
void Search(int s,int d)
{
	int i,k;
	if(d==N)
	{
		printf("%d\n",s);
		return;
	}
	for(i=1;i<=9;++i)
		if(i&1 && check(k=s*10+i))
			Search(k,d+1);
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&N);
	Search(2,1);
	Search(3,1);
	Search(5,1);
	Search(7,1);
	return 0;
}