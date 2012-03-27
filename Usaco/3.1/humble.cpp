/*
ID: xfstart2
LANG: C++
PROG: humble
*/
#include<fstream>
using namespace std;

ifstream cin("humble.in");
ofstream cout("humble.out");

int N,M;
int a[101];
int x[101];
int F[100010];
int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;++i)
		cin>>a[i],x[i]=0;
	F[0]=1; int m=0;
	while(m<M)
	{
		for(int i=1;i<=N;++i)
			if(F[m] >= F[x[i]]*a[i])
				x[i]++;
		int Min=0x7FFFFFFF;
		for(int i=1;i<=N;++i)
			if(Min > F[x[i]]*a[i])
				Min=F[x[i]]*a[i];
		F[++m]=Min;
	}
	cout<<F[M]<<endl;
	return 0;
}