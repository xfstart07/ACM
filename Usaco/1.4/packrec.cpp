/*
ID: xfstart2
LANG: C++
PROG: packrec
*/
#include<fstream>
#include<cstring>
using namespace std;

struct Node{
	int w,h;
};
int N,Ans;
int A[4][2];
Node S[100];
int i1,i2,i3,i4,j1,j2,j3,j4;
int w,h,w1,w2,w3,w4,h1,h2,h3,h4;
inline int max(int x,int y)
{ return x>y?x:y; }
void getwh()
{
	int i;
	if(w>h){
		i=w;w=h;h=i;
	}
	if(Ans > w*h)
	{
		Ans=w*h;
		S[N=1].w=w; S[1].h=h;
	}
	else if(Ans == w*h)
	{
		for(i=1;i<=N;++i)
			if(S[i].w==w && S[i].h==h)
				return;
		S[++N].w=w; S[N].h=h;
	}
}
void check()
{
	w1=A[i1][j1];
	w2=A[i2][j2];
	w3=A[i3][j3];
	w4=A[i4][j4];
	h1=A[i1][1-j1];
	h2=A[i2][1-j2];
	h3=A[i3][1-j3];
	h4=A[i4][1-j4];
	
	//1
	w=w1+w2+w3+w4;
	h=max(max(h1,h2),max(h3,h4));
	getwh();
	//2
	w=max(w1+w2+w3,w4);
	h=max(h1,max(h2,h3))+h4;
	getwh();
	//3
	w=max(w1+w2,w3)+w4;
	h=max(max(h1,h2)+h3,h4);
	getwh();
	//4 5
	w=w1+max(w2,w3)+w4;
	h=max(max(h1,h2+h3),h4);
	getwh();
	//6
	h=max(h1+h2,h3+h4);
	if(h4>=h1+h2)
		w=max(w3,max(w1+w4,w2+w4));
	if(h2>=h3+h4)
		w=max(w1,max(w2+w3,w2+w4));
	if(h2>h4&&h2<h3+h4)
		w=max(w1+w3,max(w2+w3,w2+w4));
	if(h4>h2&&h4<h1+h2)
		w=max(w1+w3,max(w1+w4,w2+w4));
	if(h2==h4)
		w=max(w1+w3,w2+w4);
	getwh();
}
int main()
{
	ifstream cin("packrec.in");
	int i,j;
	for(i=0;i<4;++i)
		cin>>A[i][0]>>A[i][1];
	Ans=0xFFFFFFF;
	for(i1=0;i1<4;++i1)
		for(i2=0;i2<4;++i2) if(i1!=i2)
			for(i3=0;i3<4;++i3) if(i1!=i3&&i3!=i2)
			{
				i4=6-i1-i2-i3;
				for(j1=0;j1<2;++j1)
					for(j2=0;j2<2;++j2)
						for(j3=0;j3<2;++j3)
							for(j4=0;j4<2;++j4)
								check();
			}
	Node tmp;
	for(i=1;i<N;++i)
		for(j=i+1;j<=N;++j)
			if(S[i].w > S[j].w || S[i].w == S[j].w && S[i].h > S[j].h)
			{
				tmp=S[i]; S[i]=S[j]; S[j]=tmp;
			}
	ofstream cout("packrec.out");
	cout<<Ans<<endl;
	for(i=1;i<=N;++i)
		cout<<S[i].w<<" "<<S[i].h<<endl;
	return 0;
}