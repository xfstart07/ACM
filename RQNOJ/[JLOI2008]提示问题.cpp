#include<iostream>
#include<string>
using namespace std;

const string ys="aeiouAEIOU";
bool check(char c){
    if(c>='A'&&c<='Z'||c>='a'&&c<='z') return 1;
    return 0;
}
bool check1(char c){
    for(int i=0;i<ys.size();++i)
        if(c==ys[i]) return 1;
    return 0;
}
int main()
{
    string s,s1,s2;
    getline(cin,s);
    s1=s;
    int l=0;
    for(int i=0;i<s.size();++i)
        if(check(s[i])){ s1[i]='.'; ++l; }
    cout<<s1<<endl;
    double t=l/3.0;
    int i=0;
    s2=s1;
    while(t>0.43&&i<s.size()){
        if(check(s[i])){
            s2[i]=s[i];
            t-=1.0;
        }
        ++i;
    }
    cout<<s2<<endl;
    bool bo=0;
    if(i<s.size())
        for(int j=i;j<s.size();++j)
            if(check1(s[j])){ s2[j]=s[j]; bo=1; }
    if(bo) cout<<s2<<endl;
    else{
        s2=s1;
        t=l/3.0*2.0,i=0;
        while(t>0.43&&i<s.size()){
            if(check(s[i])){
                s2[i]=s[i];
                t-=1.0;
            }
            ++i;
        }
        cout<<s2<<endl;
    }
    return 0;
}
