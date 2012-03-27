/*
 * Subject: STL vectox
 * Program: assign / void assign(size_type n, const T& u)
 * Time: 13/3/2011
 * Anthor: Xu Fei
 */
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> first;
    vector<int> second;
    vector<int> third;

    first.assign(7,100);
    
    vector<int>::iterator it;
    it=first.begin()+1;
    
    second.assign(it,first.end()-1);

    int myints[]={1776,7,4};
    third.assign(myints,myints+3);
    
    cout<<"Size of first: "<<(int)first.size()<<endl;
    cout<<"Size of second: "<<(int)second.size()<<endl;
    cout<<"Size of third: "<<(int)third.size()<<endl;
    return 0;
}
