/*
ID: xfstart2
LANG: C++
PROG: contact
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

const int MAXN=10000;

int A,B,N,Len,Ls;
int L[MAXN];
int hash[MAXN];
string S,hashStr[MAXN],Str[MAXN];

void init()
{
	string ch;
	cin>>A>>B>>N;
	S="1";
	while(cin>>ch)
		S+=ch;
	Ls=S.size()-1;
}
bool check(string s1,string s2)
{
	int i;
	if(s1.size() > s2.size())
		return 1;
	else if(s1.size() < s2.size())
		return 0;
	for(i=0;i<(int)s1.size();++i)
		if(s1[i] > s2[i])
			return 1;
		else if(s1[i] < s2[i])
			return 0;
	return 0;
}
void swap(int i,int j)
{
	int tmpL;
	string tmpStr;
	tmpL=L[i]; L[i]=L[j]; L[j]=tmpL;
	tmpStr=Str[i]; Str[i]=Str[j]; Str[j]=tmpStr;
}
void Qsort(int s,int t)
{
	int i=s,j=t,mid=L[(s+t)>>1];
	string midStr=Str[(s+t)>>1];
	while(i<=j)
	{
		while(mid < L[i] || (mid == L[i] && check(midStr,Str[i]))) i++;
		while(mid > L[j] || (mid == L[j] && check(Str[j],midStr))) --j;
		if(i<=j)
		{
			swap(i,j);
			i++; --j;
		}
		else
			break;
	}
	if(i<t) Qsort(i,t);
	if(s<j) Qsort(s,j);
}
void solve()
{
	int i,j,k,p;
	string ch;
	memset(hash,0,sizeof(hash));
	
	for(i=A;i<=B;++i)
		for(j=i;j<=Ls;++j)
		{
			p=1; ch="";
			for(k=j-i+1;k<=j;++k)
			{
				p=(p<<1)+S[k]-'0';
				ch+=S[k];
			}
			if(!hash[p])
				hashStr[p]=ch;
			hash[p]++;
		}
	
	memset(L,0,sizeof(L));
	Len=0;
	for(i=0;i<MAXN;++i)
		if(hash[i])
		{
			L[++Len]=hash[i];
			Str[Len]=hashStr[i];
		}
	Qsort(1,Len);
}
void output()
{
	int i,j,k;
	
	if(N > Len) N=Len;
	
	for(i=1;N && i<=Len;--N)
	{
		k=1; j=i+1;
		while(j<=Len && L[i] == L[j]) k++,j++;
		cout<<L[i]<<endl;
		for(j=1;j<k;++j)
			if(j%6 == 0)
				cout<<Str[i+j-1]<<endl;
			else
				cout<<Str[i+j-1]<<" ";
		cout<<Str[i+k-1]<<endl;
		
		i=i+k;
	}
}
int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	
	init();
	solve();
	output();
	return 0;
}