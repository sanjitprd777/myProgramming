#include <bits/stdc++.h>
using namespace std;
struct  bst{
    int data;
    struct bst *l;
    struct bst *r;
};
struct bst *root=NULL;
void insertdata(){
    int item;
    struct bst *n;
    n=(struct bst*)malloc(sizeof(struct bst));
    cout<<"Enter the data : ";
    cin>>item;
    n->r=NULL;
    n->data=item;
    n->l=NULL;
    if(root==NULL)
        root=n;
    else{
        struct bst *p;
        p=root;
        while(p!=NULL){
            if(item<p->data){
                if(p->l==NULL){
                    p->l=n;
                    break;
                }
                p=p->l;
            }
            else{
                if(p->r==NULL){
                    p->r=n;
                    break;
                }
                p=p->r;
            }
        }
    }
}
void preOrder(struct bst *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        preOrder(p->l);
        preOrder(p->r);
    }
}
void postOrder(struct bst *p){
    if(p!=NULL){
        postOrder(p->l);
        postOrder(p->r);
        cout<<p->data<<" ";
    }
}
void inOrder(struct bst *p){
    if(p!=NULL){
        inOrder(p->l);
        cout<<p->data<<" ";
        inOrder(p->r);
    }
}
int main(){
  //  system("COLOR fa");
    int n,i;
    cout<<"This is BINARY TREE for perOrder , postOrder , inOrder traversal"<<endl;
    cout<<"Enter the data you have : ";
    cin>>n;
    for(i=0;i<n;++i)
        insertdata();
    cout<<"This is preOrder Traversal"<<endl;
        preOrder(root);
    cout<<endl<<"This is inOrder Traversal"<<endl;
        inOrder(root);
    cout<<endl<<"This is postOrder Traversal"<<endl;
        postOrder(root);
    return 0;
}
