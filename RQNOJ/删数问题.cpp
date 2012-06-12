/* Ì°ÐÄ*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i;
    string s;
    getline(cin,s);
    cin>>n;
    bool bo=1;
    for(int t=0;t<n;++t){
        i=1;
        while(i<s.size()){
            if(s[i]<s[i-1]){
                s.erase(s.begin()+(i-1),s.begin()+i);
                break;
            }
            i++;
        }
        if(i==s.size()) s.erase(s.begin()+(i-1),s.begin()+i);
        if(!s.size()){ bo=0; break; }
    }
    if(!bo) cout<<0<<endl;
    else{
        i=0;
        while(s.size()>1&&s[i]=='0') s.erase(s.begin()+i,s.begin()+(i+1));
        cout<<s<<endl;
    }
    return 0;
}
