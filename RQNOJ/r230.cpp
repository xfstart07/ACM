#include<cstdio>
#include<cstring>
using namespace std;

int N,M,T;
int l1,l2,l3;
char s[3][55];
int make(int x,int y,int lx,int ly,int kx,int ky,int n,int m,int t){
	int l=0;
	for(int i=kx,j=ky;i<lx&&j<ly;++i,++j)
		if(s[x][i]==s[y][j]) l++;
		else break;
	return n-l+m-l+t+l;
}
int main()
{
	scanf("%d%s%d%s%d%s",&N,s[0],&M,s[1],&T,s[2]);
	if(strcmp(s[0],s[1])==0&&strcmp(s[1],s[2])==0){
		printf("0\n"); return 0;
	}
	l1=strlen(s[0]); l2=strlen(s[1]); l3=strlen(s[2]);
	if(s[0][0]==s[1][0]&&s[1][0]==s[2][0]){
		int l=0,Min,i,j,k;
		for(i=0,j=0,k=0;i<l1&&j<l2&&k<l3;++i,++j,++k)
			if(s[0][i]==s[1][j]&&s[1][j]==s[2][k]) l++;
			else break;
		Min=N-l+M-l+T-l;  int t=0;
		if(s[0][i]==s[1][j]){
			t=make(0,1,N,M,i,j,N-l,M-l,T-l);
			if(Min>t) Min=t;
		}
		else if(s[0][i]==s[2][k]){
			t=make(0,2,N,T,i,k,N-l,T-l,M-l);
			if(Min>t) Min=t;
		}
		else if(s[1][j]==s[2][k]){
			t=make(1,2,M,T,j,k,M-l,T-l,N-l);
			if(Min>t) Min=t;
		}
		printf("%d\n",Min);
	}
	else if(s[0][0]!=s[1][0]&&s[0][0]!=s[2][0]&&s[1][0]!=s[2][0])
		printf("%d\n",N+M+T);
	else{
		if(s[0][0]==s[1][0])
			printf("%d\n",make(0,1,N,M,0,0,N,M,T));
		else if(s[0][0]==s[2][0])
			printf("%d\n",make(0,2,N,T,0,0,N,T,M));
		else if(s[1][0]==s[2][0])
			printf("%d\n",make(1,2,M,T,0,0,M,T,N));
	}
	return 0;
}