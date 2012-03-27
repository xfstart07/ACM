/*
ID: xfstart2
LANG: C++
PROG: preface
*/
#include<cstdio>
#include<cstring>
using namespace std;

int N;
int a[8];

void solve(int k)
{
	int t;
	if(k>=1000)
	{
		t=k/1000; a[7]+=t;
		k-=t*1000;
	}
	if(k>=900)
	{
		a[7]++; a[5]++;
		k-=900;
	}
	if(k>=500)
	{ a[6]++; k-=500;}
	if(k>=400)
	{
		a[6]++; a[5]++; k-=400;
	}
	if(k>=100)
	{
		t=k/100; a[5]+=t;
		k-=t*100;
	}
	if(k>=90)
	{
		a[5]++; a[3]++;
		k-=90;
	}
	if(k>=50)
	{ a[4]++; k-=50;}
	if(k>=40)
	{
		a[4]++; a[3]++; k-=40;
	}
	a[3]+=k/10;
}
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&N);
	memset(a,0,sizeof(a));
	
	for(int i=1;i<=N;++i)
	{
		int k=i%10;
		switch(k){
			case 1: a[1]++; break;
			case 2: a[1]+=2; break;
			case 3: a[1]+=3; break;
			case 4: a[1]++; a[2]++; break;
			case 5: a[2]++; break;
			case 6: a[1]++; a[2]++; break;
			case 7: a[1]+=2; a[2]++; break;
			case 8: a[1]+=3; a[2]++; break;
			case 9: a[1]++; a[3]++; break;
		}
		if(i-k) solve(i-k);
	}
	if(a[1]) printf("I %d\n",a[1]);
	if(a[2]) printf("V %d\n",a[2]);
	if(a[3]) printf("X %d\n",a[3]);
	if(a[4]) printf("L %d\n",a[4]);
	if(a[5]) printf("C %d\n",a[5]);
	if(a[6]) printf("D %d\n",a[6]);
	if(a[7]) printf("M %d\n",a[7]);
	return 0;
}
