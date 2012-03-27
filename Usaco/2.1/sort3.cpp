/*
ID: xfstart2
LANG: C++
PROG: sort3
*/
#include<cstdio>
#include<cstring>
using namespace std;

int N;
int Ans;
int a[1001];
int l[4],s[4][4];

inline int min(int x,int y)
{ return x>y?y:x; }
inline int max(int x,int y)
{ return x>y?x:y; }
int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&N);
	memset(l,0,sizeof(l));
	for(int i=1;i<=N;++i)
		scanf("%d",a+i),l[a[i]]++;
	memset(s,0,sizeof(s));
	for(int i=1,k=1;i<=N;i+=l[k++])
	{
		for(int j=i;j<i+l[k];++j)
			s[k][a[j]]++;
	}
	Ans=0;
	for(int i=1;i<3;++i)
		for(int j=i+1;j<=3;++j)
		{
			int k=min(s[i][j],s[j][i]);
			Ans+=k;
			s[i][j]-=k; s[j][i]-=k;
		}
	printf("%d\n",Ans+max(s[1][2],s[1][3])*2);
	return 0;
}