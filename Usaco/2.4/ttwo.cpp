/*
ID: xfstart2
LANG: C++
PROG: ttwo
*/
#include<fstream>
#include<cstring>
using namespace std;

ifstream cin("ttwo.in");
ofstream cout("ttwo.out");

int N=10;
int Ans;
bool G[10][10];
bool F[10][10][10][10][4][4];
void make(int &x,int &y,int &c)
{
	if(c == 0) {
		if(x-1<0){ c=1; return; }
		if(!G[x-1][y]){ c=1; return; }
		x--;
	}
	else if(c == 1) {
		if(y+1>N-1){ c=2; return; }
		if(!G[x][y+1]){ c=2; return; }
		y++;
	}
	else if(c == 2) {
		if(x+1>N-1){ c=3; return; }
		if(!G[x+1][y]){ c=3; return; }
		x++;
	}
	else {
		if(y-1<0){ c=0; return; }
		if(!G[x][y-1]){ c=0; return; }
		y--;
	}
}
int main()
{
	int x1,y1,c1,x2,y2,c2; char c;
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			cin>>c;
			if(c == '*')
				G[i][j]=0;
			else if(c == '.')
				G[i][j]=1;
			else if(c == 'C')
			{
				G[i][j]=1;
				x1=i; y1=j;
			}
			else {
				G[i][j]=1;
				x2=i; y2=j;
			}
		}
	c1=c2=0;
	memset(F,1,sizeof(F));
	Ans=0;
	while(true) {
		F[x1][y1][x2][y2][c1][c2]=0;
		make(x1,y1,c1);
		make(x2,y2,c2);
		Ans++;
		if(x1==x2 && y1==y2) break;
		if(F[x1][y1][x2][y2][c1][c2] == 0)
		{
			Ans=0;
			break;
		}
	}
	cout<<Ans<<endl;
	return 0;
}