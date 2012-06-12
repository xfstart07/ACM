#include<iostream>
#include<string>
#define max(a,b)(a>b?a:b)
using namespace std;

int main()
{
    int n,r1[710],b1[710],rr[710],br[710];
    string s;
    cin>>n>>s;
    s+=s;
    r1[0]=b1[0]=rr[s.size()]=br[s.size()]=0;
    for(int i=0;i<s.size();++i)
        if(s[i]=='w'){
            r1[i+1]=r1[i]+1;
            b1[i+1]=b1[i]+1;
        }
        else if(s[i]=='r'){
            r1[i+1]=r1[i]+1;
            b1[i+1]=0;
        }
        else{
            r1[i+1]=0;
            b1[i+1]=b1[i]+1;
        }
    for(int i=s.size()-1;i>=0;--i)
        if(s[i]=='w'){
            rr[i+1]=rr[i+2]+1;
            br[i+1]=br[i+2]+1;
        }
        else if(s[i]=='r'){
            rr[i+1]=rr[i+2]+1;
            br[i+1]=0;
        }
        else{
            rr[i+1]=0;
            br[i+1]=br[i+2]+1;
        }
    int re=0;
    for(int i=1;i<=2*n;++i)
        re=max(re,max(r1[i],b1[i])+max(rr[i+1],br[i+1]));
    if(re>n) re=n;
    cout<<re<<endl;
    return 0;
}
