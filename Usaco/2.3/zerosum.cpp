/*
ID: xfstart2
LANG: C++
PROG: zerosum
*/
#include<fstream>
using namespace std;

ifstream cin("zerosum.in");
ofstream cout("zerosum.out");

int N;
int a[20];
void dfs(int n)
{
	if(n == N)
	{
		int i=2,s=a[1],k;
		while(i<=N*2+1)
		{
			if(a[i] == -1)
			{
				i++; k=a[i++];
				while(i<=N*2+1 && a[i] == -3)
				{
					k=k*10+a[++i];
					i++;
				}
				s+=k;
			}
			else if(a[i] == -2)
			{
				i++; k=a[i++];
				while(i<=N*2+1 && a[i] == -3)
				{
					k=k*10+a[++i];
					i++;
				}
				s-=k;
			}
			else {
				i++; k=a[i++]; s=s*10;
				while(i<=N*2+1 && a[i] == -3)
				{
					k=k*10+a[++i];
					s=s*10;
					i++;
				}
				s+=k;
			}
		}
		if(s == 0)
		{
			for(int i=1;i<=N*2+1;++i)
				if(a[i]>0) cout<<a[i];
				else if(a[i] == -1) cout<<'+';
				else if(a[i] == -2) cout<<'-';
				else if(a[i] == -3) cout<<' ';
			cout<<endl;
		}
	}
	else
	{
		a[2*n]=-3; dfs(n+1);
		a[2*n]=-1; dfs(n+1);
		a[2*n]=-2; dfs(n+1);
	}
}
int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
		a[i*2+1]=i+1;
	dfs(1);
	return 0;
}