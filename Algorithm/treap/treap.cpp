#include<iostream>
#include<ctime>
using namespace std;

const int kMAX = 100;

class Treap {
public:
    struct Node {
        int lch,rch;
        int key,fix;
    };
    
    Node P[kMAX];
    int size,root;
    
    Treap():size(-1),root(-1) {}
    
    void Rot_l(int &x) {
        int y = P[x].rch;
        P[x].rch = P[y].lch;
        P[y].lch = x;
        x = y;
    }
    
    void Rot_r(int &x) {
        int y = P[x].lch;
        P[x].lch = P[y].rch;
        P[x].rch = x;
        x = y;
    }
    
    void Insert(int  &k,int key) {
        if (k == -1) {
            k = ++size;
            P[k].lch = P[k].rch = -1;
            P[k].key = key;
            P[k].fix = rand();
        } else if (P[k].key > key) {
            Insert(P[k].lch,key);
            if (P[P[k].lch].fix > P[k].fix) {
                Rot_r(k);
            }
        } else {
            Insert(P[k].rch,key);
            if (P[P[k].rch].fix > P[k].fix) {
                Rot_l(k);
            }
        }
    }
    
    void Remove(int &k,int key) {
        if (k == -1) {
            return;
        }
        if (P[k].key > key) {
            Remove(P[k].lch,key);
        } else if (key > P[k].key) {
            Remove(P[k].rch,key);
        } else {
            if (P[k].lch == -1 && P[k].rch == -1) {
                k = -1;
            } else if (P[k].lch == -1) {
                k = P[k].rch;
            } else if (P[k].rch == -1) {
                k = P[k].lch;
            } else if (P[P[k].lch].fix < P[P[k].rch].fix) {
                Rot_l(k);
                Remove(P[k].lch,key);
            } else {
                Rot_r(k);
                Remove(P[k].rch,key);
            }
        }
    }
    
    void Print(int k) {
        if (P[k].lch != -1) {
            Print(P[k].lch);
        }
        cout<<P[k].key<<" : "<<P[k].fix<<endl;
        if (P[k].rch != -1) {
            Print(P[k].rch);
        }
    }
};

int main()
{
    Treap tree;
    for (int i=3;i>=1;--i) {
        tree.Insert(tree.root,i);
    }
    tree.Print(tree.root);
    for (int i=3;i>=1;--i) {
        cout<<endl;
        tree.Remove(tree.root,i);
        tree.Print(tree.root);
    }
}
