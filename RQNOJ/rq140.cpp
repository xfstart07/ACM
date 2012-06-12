#include<iostream>
using namespace std;

int N,T,n;
int a[12][110];
int f[12][110];
int main()
{
	cin>>T>>N>>n;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=T;++j)
			cin>>a[i][j];
	for(int i=1;i<=N;++i)
		for(int j=1;j<=T;++j){
			f[i][j]=f[i-1][j];
			for(int k=0;k<=j;++k)
				if(k-n>=0)
					if(f[i][j]<f[i-1][j-k]+a[i][k-n])
						f[i][j]=f[i-1][j-k]+a[i][k-n];
		}
	cout<<f[N][T]<<endl;
	return 0;
}