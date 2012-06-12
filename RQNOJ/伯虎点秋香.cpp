#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string a[1000];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    cout<<a[k-1]<<endl;
    return 0;
}
