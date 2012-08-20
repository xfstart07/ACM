#include<iostream>
#include<ctime>
using namespace std;

struct Node {
        int element,fix;
        Node *left,*right;

        Node(int e,int f,Node *l,Node *r):
            element(e),fix(f),left(l),right(r) {}
};

class Treap {
public:
    Node *root;

    // ×óÐý
    void LeftRotate(Node *&p) {
        Node *t = p->right;
        p->right = t->left;
        t->left = p;
        p = t;
    }

    // ÓÒÐý
    void RightRotate(Node *&p) {
        Node *t = p->left;
        p->left = t->right;
        t->right = p;
        p = t;
    }

    // ²åÈë
    void Insert(Node *&p,int element) {
        if (!p) {
            p = new Node(element,rand(),0,0);
        } else if (p->element >= element) {
            Insert(p->left,element);
            if (p->left->fix < p->fix) {
                RightRotate(p);
            }
        } else {
            Insert(p->right,element);
            if (p->right->fix < p->fix) {
                LeftRotate(p);
            }
        }
    }

    // É¾³ý
    void Remove(Node *&p,int element) {
        if (!p) {
            return;
        }
        if (p->element == element) {
            if (!p->left || !p->right) {
                Node *t = p;
                p = (p->left)?p->left:p->right;
                delete t;
            } else {
                if (p->left->fix > p->right->fix) {
                    LeftRotate(p);
                    Remove(p->left,element);
                } else {
                    RightRotate(p);
                    Remove(p->right,element);
                }
            }
        }
        else {
            if (p->element > element) {
                Remove(p->left,element);
            } else {
                Remove(p->right,element);
            }
        }
    }
    
    // Ñ°ÕÒ min
    Node* FindMin(Node *p) {
        while (p->left) {
            p = p->left;
        }
        return p;
    }

    // Ñ°ÕÒ max
    Node* FindMax(Node *p) {
        while (p->right) {
            p = p->right;
        }
        return p;
    }
    
    // ²éÕÒ
    bool Find(Node *p,int element) {
        if (!p) {
            return false;
        }
        if (p->element > element) {
            return Find(p->left,element);
        } else if (p->element < element) {
            return Find(p->right,element);
        } else {
            return true;
        }
    }

    // Ç°Çý
    Node* pred(Node *p,int element,Node *optimal) {
        if (!p) {
            return optimal;
        }
        if (p->element <= element) {
            return pred(p->right,element,p);
        } else {
            return pred(p->left,element,optimal);
        }
    }
    
    // ºó¼Ì
    Node* succ(Node *p,int element,Node *optimal) {
        if (!p) {
            return optimal;
        }
        if (p->element >= element) {
            return succ(p->left,element,p);
        } else {
            return succ(p->right,element,optimal);
        }
    }
    
    // ´òÓ¡
    void Print(Node *p) {
        if (!p) {
            return;
        } else {
            Print(p->left);
            printf("%d\n",p->element);
            Print(p->right);
        }
    }
};

int main()
{
    srand(0);

    Treap tree;
    int n,m,x;
    char s[3];

    cin>>n>>m;
    tree.root = 0;
    for (int i=0;i<n;++i) {
        cin>>x;
        tree.Insert(tree.root,x);
    }

    tree.Print(tree.root);

    for (int i=0;i<m;++i) {
        cin>>s>>x;
        if (s[0] == 'I') {
            tree.Insert(tree.root,x);
        } else if (s[0] == 'D') {
            tree.Remove(tree.root,x);
        }
    }

    tree.Print(tree.root);
    
    Node *Min,*Max;
    Min = tree.FindMin(tree.root);
    Max = tree.FindMax(tree.root);
    
    printf("Min = %d\n",Min->element);
    printf("Max = %d\n",Max->element);
    
    Node *pred,*succ;
    pred = tree.pred(tree.root,3,0);
    succ = tree.succ(tree.root,3,0);
    
    printf("pred = ");
    if (!pred) {
        printf("NULL\n");
    } else {
        printf("%d\n",pred->element);
    }
    
    printf("succ = ");
    if (!pred) {
        printf("NULL\n");
    } else {
        printf("%d\n",succ->element);
    }
    
    return 0;
}
