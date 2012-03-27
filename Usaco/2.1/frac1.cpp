/*
ID: xfstart2
LANG: C++
PROG: frac1
*/
#include<fstream>
using namespace std;

ifstream cin("frac1.in");
ofstream cout("frac1.out");

int N;
void dfs(int a,int b,int c,int d)
{
	if(a+c > N || b+d > N)
		return;
	dfs(a,b,a+c,b+d);
	cout<<a+c<<"/"<<b+d<<endl;
	dfs(a+c,b+d,c,d);
}
int main()
{
	cin>>N;
	cout<<"0/1\n";
	dfs(0,1,1,1);
	cout<<"1/1"<<endl;
	return 0;
}