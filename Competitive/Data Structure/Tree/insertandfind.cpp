#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long int
#define ull unsigned long long int
using namespace std;
struct BNT{
    int data;
    struct BNT *left,*right;
};
struct BNT *root=NULL;
void insertdata(){
    struct BNT *n,*p;
    n=(struct BNT*)malloc(sizeof(struct BNT));
    int item;
    cout<<"Enter the item : ";
    cin>>item;
    n->data=item;
    n->right=NULL;
    n->left=NULL;
    if(root==NULL)
        root=n;
    else{
        p=root;
        while(p!=NULL){
            if(item<p->data){
               if(p->left==NULL)
                    p->left=n;
                p=n->left;  //to make while loop terminate
            }
           else if(item>p->data){
                if(p->right==NULL)
                    p->right=n;
                p=n->right; //to make while loop terminate
            }
        }
    }
    return;
}
struct BNT* finddata(struct BNT *temp,int item){
    if(temp==NULL)
        return NULL;
    if(temp->data<item)
        return finddata(temp->right,item);
    else if(temp->data>item)
        return finddata(temp->left,item);

    return temp;
};
int main(){
    cout<<"THIS IS BINART TREE PROGRAMME TO INSERT DATA AND FIND IT"<<endl;
    int t;
    cout<<"Enter the number of data : ";
    cin>>t;
    while(t--)
        insertdata();
    cout<<"Enter the data to find : ";
    cin>>t;
    if(finddata(root,t)!=NULL)
        cout<<"Yes data exist in tree";
    else
        cout<<"Sorry data doesn't exist in tree";
    return 0;
}
