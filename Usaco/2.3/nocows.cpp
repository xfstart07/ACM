/*
ID: xfstart2
LANG: C++
PROG: nocows
*/
#include<fstream>
#include<cstring>
using namespace std;

int N,M;
long long F[200][100];

int main()
{
	ifstream cin("nocows.in");
	ofstream cout("nocows.out");
	cin>>N>>M;
	memset(F,0,sizeof(F));
	for(int i=1;i<=M;++i)
		F[1][i]=1;
	for(int i=3;i<=N;++i) if(i&1)
		for(int j=1;j<=M;++j)
		{
			for(int k=0;k<i;++k)
				F[i][j]+=(F[k][j-1]*F[i-k-1][j-1])%9901;
			F[i][j]%=9901;
		}
	cout<<(F[N][M]-F[N][M-1]+9901)%9901<<endl;
	return 0;
}