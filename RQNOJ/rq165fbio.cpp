#include<iostream>
using namespace std;

int n;
int f[2010];
int b[2010];
int c[2010];
char s[2010];
int main()
{
	gets(s);
	n=strlen(s);
	f[0]=b[0]=c[0]=0;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		b[i]=b[i-1];
		c[i]=c[i-1];
		if(s[i-1]=='O') continue;
		if(s[i-1]=='F')
			f[i]++;
		else if(s[i-1]=='B')
			b[i]+=f[i];
		else if(s[i-1]='I')
			c[i]+=b[i];
	}
	printf("%d\n",c[n]);
	return 0;
}