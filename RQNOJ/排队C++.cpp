#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    string s;
    char ch;
    cin>>s;
    cout<<s<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>ch;
        int p=s.find(ch);
        if((s.size()-1)/2>=p) reverse(s.begin(),s.begin()+p);
        else reverse(s.begin()+p+1,s.end());
        s.erase(s.begin()+p);
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}
