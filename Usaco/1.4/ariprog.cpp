/*
ID: xfstart2
LANG: C++
PROG: ariprog
*/
#include<fstream>
using namespace std;
struct Node{
	int a,b;
};
int N,M,L,La;
int f[251],pq[125000];
bool flg[125000];
Node Ans[10000];
int cmp(const void *A,const void *B)
{
	Node *ta=(Node *)A;
	Node *tb=(Node *)B;
	if(ta->b != tb->b)
		return ta->b - tb->b;
	else
		return ta->a - tb->a;
}
int main()
{
	ifstream cin("ariprog.in");
	int i,j,k,a,b;
	cin>>N>>M;
	
	for(i=0;i<=M;++i) f[i]=i*i;
	
	for(i=0;i<=M;++i)
		for(j=i;j<=M;++j)
			flg[f[i]+f[j]]=1;
	L=0;
	for(i=0;i<=2*M*M;++i)
		if(flg[i]) pq[++L]=i;
	
	La=-1;
	for(i=1;i<L;++i)
		for(j=i+1;j<=L;++j)
		{
			a=pq[i]; b=pq[j]-pq[i];
			if(a+b*(N-1) > 2*M*M) break;
			
			bool bo=1;
			for(k=3;k<=N;++k)
				if(!flg[a+b*(k-1)]){
					bo=0; break;
				}
			if(bo)
			{
				La++; Ans[La].a=a; Ans[La].b=b;
			}
		}
	qsort(Ans,La+1,sizeof(Node),cmp);
	ofstream cout("ariprog.out");
	for(i=0;i<=La;++i)
		cout<<Ans[i].a<<" "<<Ans[i].b<<"\n";
	if(La == -1)
		cout<<"NONE"<<endl;
	return 0;
}