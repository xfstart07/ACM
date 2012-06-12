#include<iostream>
using namespace std;

int n;
int a[12][12];
int f[30][12][12];
int main()
{
	int x,y,z;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	while(1){
		scanf("%d%d%d",&x,&y,&z);
		if(!x) break;
		a[x][y]=z;
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<2*n;++i)
		for(int j=max(1,i-n+1);j<=min(i,n);++j)
			for(int k=max(1,i-n+1);k<=min(i,n);++k){
				int tmp=0;
				if(f[i-1][j][k]>tmp)
					tmp=f[i-1][j][k];
				if(f[i-1][j-1][k]>tmp)
					tmp=f[i-1][j-1][k];
				if(f[i-1][j][k-1]>tmp)
					tmp=f[i-1][j][k-1];
				if(f[i-1][j-1][k-1]>tmp)
					tmp=f[i-1][j-1][k-1];
				if(j==k)
					tmp+=a[i-j+1][j];
				else tmp+=a[i-j+1][j]+a[i-k+1][k];
				f[i][j][k]=tmp;
			}
	printf("%d\n",f[2*n-1][n][n]);
	return 0;
}