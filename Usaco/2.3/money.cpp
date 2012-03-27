/*
ID: xfstart2
LANG: C++
PROG: money
*/
#include<fstream>
using namespace std;

int N,V;
int a[25];
long long F[10001];
int main()
{
	ifstream cin("money.in");
	ofstream cout("money.out");
	cin>>N>>V;
	for(int i=0;i<N;++i)
		cin>>a[i];
	F[0]=1;
	for(int i=1;i<=V;++i) F[i]=0;
	
	for(int i=0;i<N;++i)
		for(int j=a[i];j<=V;++j)
			F[j]+=F[j-a[i]];
	cout<<F[V]<<endl;
	return 0;
}