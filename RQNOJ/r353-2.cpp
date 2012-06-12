#include<cstdio>
#include<cstring>
using namespace std;

int N;
int a[30010];
int f[30010][4];
inline int min(int x,int y)
{ return x>y?y:x; }
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=3;++i)
		f[0][i]=f[N+1][i]=0;
	for(int i=1;i<=N;++i)
		if(a[i]==1){
			f[i][1]=f[i-1][1];
			f[i][2]=min(f[i-1][1],f[i-1][2]+1);
			f[i][3]=min(min(f[i-1][1],f[i-1][2]+1),f[i-1][3]+1);
		}
		else if(a[i]==2){
			f[i][1]=f[i-1][1]+1;
			f[i][2]=min(f[i-1][1]+1,f[i-1][2]);
			f[i][3]=min(min(f[i-1][1]+1,f[i-1][2]),f[i-1][3]+1);
		}
		else{
			f[i][1]=f[i-1][1]+1;
			f[i][2]=min(f[i-1][1]+1,f[i-1][2]+1);
			f[i][3]=min(min(f[i-1][1]+1,f[i-1][2]+1),f[i-1][3]);
		}
	int Min=0xFFFFFFF;
	for(int i=1;i<=3;++i)
		if(f[N][i]<Min) Min=f[N][i];
	for(int i=N;i>=1;--i)
		if(a[i]==1){
			f[i][1]=f[i+1][1];
			f[i][2]=min(f[i+1][1],f[i+1][2]+1);
			f[i][3]=min(min(f[i+1][1],f[i+1][2]+1),f[i+1][3]+1);
		}
		else if(a[i]==2){
			f[i][1]=f[i+1][1]+1;
			f[i][2]=min(f[i+1][1]+1,f[i+1][2]);
			f[i][3]=min(min(f[i+1][1]+1,f[i+1][2]),f[i+1][3]+1);
		}
		else{
			f[i][1]=f[i+1][1]+1;
			f[i][2]=min(f[i+1][1]+1,f[i+1][2]+1);
			f[i][3]=min(min(f[i+1][1]+1,f[i+1][2]+1),f[i+1][3]);
		}
	for(int i=1;i<=3;++i)
		if(f[1][i]<Min) Min=f[1][i];
	printf("%d\n",Min);
	return 0;
}