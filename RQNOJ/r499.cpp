#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	if(n==0){ cout<<0<<endl; return 0; }
	double ans=1;
	for(int i=2;i<=n;++i){
		double k=i;
		ans*=k;
		while(ans>10.0){
			ans=ans/10.0;
		}
	}
	int Ans=(int)ans;
	printf("%d\n",Ans);
	return 0;
}