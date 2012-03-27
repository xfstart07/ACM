/*
ID: xfstart2
LANG: C++
PROG: inflate
*/
#include<fstream>
using namespace std;

ifstream cin("inflate.in");
ofstream cout("inflate.out");

int N,M;
int F[10010]={0};

int main()
{
	cin>>N>>M;
	for(int i=1;i<=M;++i)
	{
		int a,b; cin>>a>>b;
		for(int j=b;j<=N;++j)
			if(F[j] < F[j-b]+a)
				F[j]=F[j-b]+a;
	}
	cout<<F[N]<<endl;
	return 0;
}