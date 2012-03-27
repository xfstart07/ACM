/*
ID: xfstart2
LANG: C++
PROG: barn1
*/
#undef DEBUG
#include<fstream>
using namespace std;

int N,M,S;
int Sum;
int A[200],B[200];

void init()
{
	ifstream cin("barn1.in");
	int i,j,tmp;
	cin>>M>>S>>N;
	#ifdef DEBUG
	ofstream clog("barn1.log");
	#endif
	for(i=0;i<N;++i)
		cin>>A[i];
	for(i=0;i<N;++i)
		for(j=i+1;j<N;++j)
			if(A[i] > A[j])
			{
				tmp=A[i]; A[i]=A[j]; A[j]=tmp;
			}
    #ifdef DEBUG
    for(i=0;i<N;++i) clog<<A[i]<<" ";
    #endif
	for(i=1,B[0]=0;i<N;++i)
		B[i]=A[i]-A[i-1]-1;
	for(i=0;i<N;++i)
		for(j=i+1;j<N;++j)
			if(B[i] < B[j])
			{
				tmp=B[i]; B[i]=B[j]; B[j]=tmp;
			}
}
void solve()
{
	int i;
	M=M-1>N?N:M-1;
	Sum=A[N-1]-A[0]+1;
	for(i=0;i<M;++i)
		Sum-=B[i];
	ofstream cout("barn1.out");
	cout<<Sum<<endl;
}
int main()
{
	init();
	solve();
	return 0;
}
