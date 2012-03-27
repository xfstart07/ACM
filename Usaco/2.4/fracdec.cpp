/*
ID: xfstart2
LANG: C++
PROG: fracdec
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int a[100010];
char s[100010];
int main()
{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	int x,y; 
	scanf("%d%d",&x,&y);
	sprintf(s,"%d",(int)(x/y));
	int l=strlen(s);
	s[l++]='.';
	x%=y;
	if(x==0)
		s[l++]='0';
	else {
		memset(a,0,sizeof(a));
		while(x){
			if(a[x]) break;
			a[x]=l;
			x*=10;
			s[l++]=char((int)(x/y)+48);
			x%=y;
		}
	}
	if(x){
		int t=0;
		for(int i=0;i<l;++i) {
			if(a[x] == i)
				printf("("),t++;
			if(t == 76) {
				printf("\n");
				t=0;
			}
			printf("%c",s[i]);
			t++;
			if(t == 76) {
				printf("\n");
				t=0;
			}
			
		}
		printf(")\n");
	}
	else{
		int t=0;
		for(int i=0;i<l;++i) {
			printf("%c",s[i]);
			t++;
			if(t%76 == 0) {
				printf("\n");
				t=0;
			}
		}
		printf("\n");
	}
	return 0;
}