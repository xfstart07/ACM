/*
ID: xfstart2
LANG: C++
PROG: butter
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=501,MAXP=801,MAXC=1500*2,INF=0x7FFFFFFF;
int N,P,C;
int cow[MAXN];
int dis[MAXP];
bool vis[MAXP];
int H,T,que[MAXC*MAXP];
int pre[MAXC],path[MAXC],son[MAXC],next[MAXP];

void addedge(int a,int b,int c,int &k)
{
	pre[++k]=next[a]; next[a]=k; son[k]=b; path[k]=c; 
	pre[++k]=next[b]; next[b]=k; son[k]=a; path[k]=c;
}
void input()
{
	int i,a,b,c,k=0;
	
	scanf("%d%d%d",&N,&P,&C);
	for(i=1;i<=N;++i)
		scanf("%d",cow+i);
	memset(next,0,sizeof(next));
	for(i=1;i<=C;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c,k);
	}
}
void spfa(int c,int &res)
{
	int i,x,y;
	
	for(i=1;i<=P;++i)
		dis[i]=INF,vis[i]=1;
	
	dis[c]=0; vis[c]=0;
	H=T=1; que[1]=c;
	
	while(H<=T)
	{
		x=que[H];
		for(i=next[x];i;i=pre[i])
		{
			y=son[i];
			if(dis[y] > dis[x] + path[i])
			{
				dis[y]=dis[x]+path[i];
				if(vis[y])
				{
					vis[y]=0;
					que[++T]=y;
				}
			}
		}
		H++;
		vis[x]=1;
	}
	x=0;
	for(i=1;i<=N;++i)
		x+=dis[cow[i]];
	if(res > x)
		res=x;
}
int solve()
{
	int i,res=INF;
	for(i=1;i<=P;++i)
		spfa(i,res);
	return res;
}
void output(int res)
{
	printf("%d\n",res);
}
int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	input();
	output(solve());
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 12316 KB]
   Test 2: TEST OK [0.000 secs, 12316 KB]
   Test 3: TEST OK [0.011 secs, 12316 KB]
   Test 4: TEST OK [0.011 secs, 12316 KB]
   Test 5: TEST OK [0.000 secs, 12316 KB]
   Test 6: TEST OK [0.011 secs, 12316 KB]
   Test 7: TEST OK [0.032 secs, 12316 KB]
   Test 8: TEST OK [0.065 secs, 12316 KB]
   Test 9: TEST OK [0.130 secs, 12316 KB]
   Test 10: TEST OK [0.130 secs, 12316 KB]
*/