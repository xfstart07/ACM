/*
ID: xfstart2
LANG: C++
PROG: crypt1
*/
#include<fstream>
#include<cstring>
using namespace std;

int N;
int Ans;
int A[10];
bool B[10];
bool check(int p)
{
	while(p)
	{
		if(B[p%10] == 0)
			return 1;
		p/=10;
	}
	return 0;
}
int main()
{
	ifstream cin("crypt1.in");
	int i,j,k,x,y,s1,s2;
	memset(B,0,sizeof(B));
	cin>>N;
	for(i=0;i<N;++i)
		cin>>A[i],B[A[i]]=1;
	Ans=0;
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			for(k=0;k<N;++k)
				for(x=0;x<N;++x)
					for(y=0;y<N;++y)
					{
						s1=A[i]*100+A[j]*10+A[k];
						if(s1*A[x]>999||check(s1*A[x])) break;
						if(s1*A[y]>999||check(s1*A[y])) continue;
						s2=A[x]*10+A[y];
						if(s1*s2>9999||check(s1*s2)) continue;
						Ans++;
					}
	ofstream cout("crypt1.out");
	cout<<Ans<<endl;
	return 0;
}