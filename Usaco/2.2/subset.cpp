/*
ID: xfstart2
LANG: C++
PROG: subset
*/
#include<cstdio>
#include<cstring>
using namespace std;

int N,S;
long long F[750];
int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%d",&N);
	S=(N+1)*N/2;
	if(S % 2 == 0)
	{
		S/=2;
		F[0]=1;
		for(int i=1;i<=N;++i)
			for(int j=S;j>=i;--j)
				F[j]+=F[j-i];
		printf("%lld\n",F[S]/2);
	}
	else
		printf("0\n");
	return 0;
}