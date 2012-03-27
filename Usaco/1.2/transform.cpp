/*
ID: xfstart2
LANG: C++
PROG: transform
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool turn1(const char A[10][10]);
bool turn2(const char A[10][10]);
bool turn3(const char A[10][10]);
bool turn4(const char A[10][10]);
bool turn5(const char A[10][10]);
bool turn6(const char A[10][10]);
bool equal(const char A[10][10]);

int N;
char end[10][10]={0};

int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	int i;
	char beg[10][10]={0};
	
	scanf("%d",&N);
	for(i=0;i<N;++i)
		scanf("%s",beg[i]);
	for(i=0;i<N;++i)
		scanf("%s",end[i]);
	
	if(turn1(beg))
		printf("1\n");
	else if(turn2(beg))
		printf("2\n");
	else if(turn3(beg))
		printf("3\n");
	else if(turn4(beg))
		printf("4\n");
	else if(turn5(beg))
		printf("5\n");
	else if(turn6(beg))
		printf("6\n");
	else
		printf("7\n");
	return 0;
}

int i,j;

bool equal(const char A[10][10])
{
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			if(A[i][j] != end[i][j])
				return 0;
	return 1;
}

bool turn1(const char A[10][10])
{
	char B[10][10]={0};
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			B[i][j]=A[N-j-1][i];
	return equal(B);
}

bool turn2(const char A[10][10])
{
	char B[10][10]={0};
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			B[i][j]=A[N-i-1][N-j-1];
	return equal(B);
}

bool turn3(const char A[10][10])
{
	char B[10][10]={0};
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			B[i][j]=A[j][N-i-1];
	return equal(B);
}

bool turn4(const char A[10][10])
{
	char B[10][10]={0};
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			B[i][j]=A[i][N-j-1];
	return equal(B);
}

bool turn5(const char A[10][10])
{
	char B[10][10]={0};
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			B[i][j]=A[i][N-j-1];
	if(turn1(B)) return 1;
	if(turn2(B)) return 1;
	if(turn3(B)) return 1;
	return 0;
}

bool turn6(const char A[10][10])
{
	return equal(A);
}