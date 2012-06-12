#include<iostream>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int ans=0,d[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    for(int i=0;i<s.size();++i)
        if(s[i]!=' ')
            ans+=d[s[i]-'a'];
        else ans++;
    cout<<ans<<endl;
    return 0;
}
