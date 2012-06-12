#include<iostream>
using namespace std;

int n;
bool a[1010][1010];
bool f[1010][1010];
int Win[501];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			int c;
			scanf("%d",&c);
			a[i][j]=a[i+n][j]=a[i][j+n]=a[i+n][j+n]= c==1;
		}
	for(int i=1;i<=2*n;++i)
		f[i][i+1]=1;
	for(int k=3;k<=n+1;++k)
		for(int i=1;i<=2*n-k+1;++i){
			int j=i+k-1;
			for(int t=i+1;t<j;++t)
				if(f[i][t]&&f[t][j]&&(a[i][t]||a[j][t])){
					f[i][j]=1;
					break;
				}
		}
	int l=0;
	for(int i=1;i<=n;++i)
		if(f[i][i+n])
			Win[++l]=i;
	printf("%d\n",l);
	for(int i=1;i<=l;++i)
		printf("%d\n",Win[i]);
	return 0;
}