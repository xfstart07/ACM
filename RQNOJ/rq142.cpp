#include<iostream>
using namespace std;

int N;
int dis[110];
bool vis[110];
int a[110][110];
int main()
{
	cin>>N;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			cin>>a[i][j];
	for(int i=1;i<=N;++i)
		dis[i]=a[1][i],vis[i]=1;
	dis[1]=0; vis[1]=0; int Ans=0;
	for(int k=1;k<N;++k){
		int Min=0xFFFFFFF,Minj;
		for(int i=1;i<=N;++i)
			if(vis[i]&&Min>dis[i])
				Min=dis[i],Minj=i;
		if(Min==0xFFFFFFF) break;
		Ans+=Min;
		vis[Minj]=0;
		for(int i=1;i<=N;++i)
			if(vis[i]&&dis[i]>a[Minj][i])
				dis[i]=a[Minj][i];
	}
	cout<<Ans<<endl;
	return 0;
}