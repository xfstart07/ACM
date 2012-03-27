#include<iostream>
#include<cstring>
using namespace std;

int N;
int res,Ans[3][14],tmp[14];
bool row[15],l[30],r[30];
void dfs(int i)
{
	if(i>N)
	{
		if(res == 3)
			res++;
		else{
			memcpy(Ans[res],tmp,sizeof(tmp));
			res++;
		}
	}
	else{
		for(int j=1;j<=N;++j)
			if(row[j] && l[i+j] && r[13+i-j])
			{
				row[j]=l[i+j]=r[13+i-j]=0;
				tmp[i]=j;
				dfs(i+1);
				row[j]=l[i+j]=r[13+i-j]=1;
			}
	}
}
int main()
{
	cin>>N;
	memset(row,1,sizeof(row));
	memset(l,1,sizeof(l));
	memset(r,1,sizeof(r));
	res=0;
	for(int i=1;i<=N;++i)
		if(row[i] && l[i+1] && r[13+1-i])
		{
			row[i]=l[i+1]=r[13+1-i]=0;
			tmp[1]=i;
			dfs(2);
			row[i]=l[i+1]=r[13+1-i]=1;
		}
	for(int i=0;i<3;++i)
	{
		for(int j=1;j<N;++j)
			cout<<Ans[i][j]<<" ";
		cout<<Ans[i][N]<<endl;
	}
	cout<<res<<endl;
	return 0;
}