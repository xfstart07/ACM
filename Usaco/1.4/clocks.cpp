/*
ID: xfstart2
LANG: C++
PROG: clocks
*/
#include<fstream>
using namespace std;

int A[9];
int L,Ans[100];
inline void make(int &x)
{
	x+=3;
	if(x>12) x=3;
}
inline bool equal(const int *x)
{
	int i;
	for(i=0;i<9;++i)
		if(x[i]!=12)
			return 0;
	return 1;
}
void check(int i1,int i2,int i3,int i4,int i5,int i6,int i7,int i8,int i9)
{
	int i,l=0,res[100],B[9];
	for(i=0;i<9;++i) B[i]=A[i];
	//0134
	while(i1--)
	{
		make(B[0]);make(B[1]);make(B[3]);make(B[4]);
		res[++l]=1;
	}
	//012
	while(i2--)
	{
		make(B[0]);make(B[1]);make(B[2]);
		res[++l]=2;
	}
	//1245
	while(i3--)
	{
		make(B[1]);make(B[2]);make(B[4]);make(B[5]);
		res[++l]=3;
	}
	//036
	while(i4--)
	{
		make(B[0]);make(B[3]);make(B[6]);
		res[++l]=4;
	}
	//13457
	while(i5--)
	{
		make(B[1]);make(B[3]);make(B[4]);make(B[5]);make(B[7]);
		res[++l]=5;
	}
	//258
	while(i6--)
	{
		make(B[2]);make(B[5]);make(B[8]);
		res[++l]=6;
	}
	//3467
	while(i7--)
	{
		make(B[3]);make(B[4]);make(B[6]);make(B[7]);
		res[++l]=7;
	}
	//678
	while(i8--)
	{
		make(B[6]);make(B[7]);make(B[8]);
		res[++l]=8;
	}
	//4578
	while(i9--)
	{
		make(B[4]);make(B[5]);make(B[7]);make(B[8]);
		res[++l]=9;
	}
	if(equal(B))
	{
		if(l>L) return;
		if(l==L)
			for(i=1;i<=l;++i)
				if(res[i]>Ans[i])
					return;
				else if(res[i]<Ans[i])
					break;
		L=l;
		for(i=1;i<=l;++i)
			Ans[i]=res[i];
	}
}
int main()
{
	ifstream cin("clocks.in");
	int i,i1,i2,i3,i4,i5,i6,i7,i8,i9;
	for(i=0;i<9;++i)
		cin>>A[i];
	L=100;
	for(i1=0;i1<4;++i1)
		for(i2=0;i2<4;++i2)
			for(i3=0;i3<4;++i3)
				for(i4=0;i4<4;++i4)
					for(i5=0;i5<4;++i5)
						for(i6=0;i6<4;++i6)
							for(i7=0;i7<4;++i7)
								for(i8=0;i8<4;++i8)
									for(i9=0;i9<4;++i9)
										check(i1,i2,i3,i4,i5,i6,i7,i8,i9);
	ofstream cout("clocks.out");
	for(i=1;i<L;++i)
		cout<<Ans[i]<<" ";
	cout<<Ans[L]<<endl;
	return 0;
}