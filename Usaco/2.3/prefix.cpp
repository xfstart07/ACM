/*
ID: xfstart2
LANG: C++
PROG: prefix
*/
#include<cstdio>
#include<cstring>


int N,Len;
int L[201];
bool F[200001];
char Str[200001];
char S[201][10];

bool check(int x,int y)
{
	for(int ii=x-L[y]+1,jj=0;jj<L[y];++ii,++jj)
		if(Str[ii] != S[y][jj])
			return 0;
	return 1;
}
int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	char c,ch[80];
	N=0;
	while(scanf("%s",ch) && ch[0]!='.')
	{
		strcpy(S[++N],ch);
		L[N]=strlen(ch);
	}
	getchar();
	Len=0;
	while(scanf("%c",&c)!=EOF)
		if(c!='\n')
			Str[++Len]=c;
	
	F[0]=1;
	for(int i=1;i<=Len;++i)
		for(int j=1;j<=N;++j)
			if(i>=L[j] && F[i-L[j]])
				if(check(i,j))
				{
					F[i]=1; break;
				}
	int i=Len;
	while(!F[i]) i--;
	printf("%d\n",i);
	return 0;
}