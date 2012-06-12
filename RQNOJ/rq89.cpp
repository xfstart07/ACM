#include<iostream>
#include<cstring>
using namespace std;

struct arr{
	int x,y;
};
struct node{
	int x,y,step;
}que[10010];
int N,M;
int Map[110][110];
bool v[110][110];
arr xy[26],d[110][110];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
void init()
{
	string s;
	cin>>N>>M;
	memset(Map,0,sizeof(Map));
	memset(xy,0,sizeof(xy));
	for(int i=1;i<=N;++i){
		cin>>s;
		for(int j=1;j<=M;++j){
			if(s[j-1]=='0')
				Map[i][j]=1;
			else if(s[j-1]=='1')
				Map[i][j]=0;
			else if(s[j-1]>='A'&&s[j-1]<='Z'){
				Map[i][j]=2;
				d[i][j].x=i; d[i][j].y=j;
				int ch=s[j-1]-'A';
				if(xy[ch].x==0) xy[ch].x=i,xy[ch].y=j;
				else{
					arr tmp=d[xy[ch].x][xy[ch].y];
					d[xy[ch].x][xy[ch].y]=d[i][j];
					d[i][j]=tmp;
				}
			}
		}
	}
}
void BFS()
{
	memset(v,1,sizeof(v));
	int head,tail;
	head=tail=1; 
	que[1].x=1; que[1].y=1; 
	que[1].step=0;
	v[1][1]=0;
	while(head<=tail){
		int x=que[head].x,y=que[head].y;
		for(int i=0;i<4;++i){
			int xi=x+dx[i],yi=y+dy[i];
			if(Map[xi][yi]==2){
				int xx=xi,yy=yi;
				xi=d[xx][yy].x; yi=d[xx][yy].y;
			}
			if(v[xi][yi]==0||Map[xi][yi]==0) 
				continue;
			v[xi][yi]=0;
			tail++; que[tail].x=xi; que[tail].y=yi;
			que[tail].step=que[head].step+1;
			if(xi==N&&yi==M){
				cout<<que[tail].step<<endl;
				return;
			}
		}
		head++;
	}
	cout<<"No Solution.\n";
}
int main()
{
	init();
	BFS();
	return 0;
}