#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct BST{
    int data;
    struct BST *lc,*rc;
};
struct BST *root=NULL;
void insert(){
    int x;
    cout<<"Enter value : ";
    cin>>x;
    struct BST *node;
    node=new(BST);
    node->data=x;  node->lc=NULL;   node->rc=NULL;
    if(root==NULL)
        root=node;
    else{
        struct BST *p=root,*q;
        while(p!=NULL){
            q=p;
            if(p->data>node->data)
                p=p->lc;
            else if(p->data<node->data)
                p=p->rc;
            else{
                cout<<"Duplicate values!"<<endl;
                return;
            }
        }
        if(x>q->data)
            q->rc=node;
        else
            q->lc=node;
    }
}
void del(){
    struct BST *c,*p=root,*q=NULL;
    if(p==NULL){
        cout<<"Empty BST tree"<<endl;
        return;
    }
    int key;
    cout<<"Enter Key to delete : ";
    cin>>key;
    // p is the node to be deleted;  q is the parent of p
    while(p!=NULL){
        if(p->data==key)
            break;
        q=p;
        if(p->data>key)
            p=p->lc;
        else
            p=p->rc;
    }
    key=p->data;
    // when deleted node has both child.
    if(p->lc!=NULL&&p->rc!=NULL){
        struct BST *s,*ps;
        ps=p;
        s=p->rc;
        while(s->lc!=NULL){
            ps=s;
            s=s->lc;
        }
        p->data=s->data;
        q=ps;
        p=s;
    }
    if(p->lc==NULL)
        c=p->rc;
    else
        c=p->lc;
    if(q==NULL)
        root=c;
    else if(p==q->lc)
        q->lc=c;
    else
        q->rc=c;
    cout<<"Key "<<key<<" Successfully deleted!"<<endl;
    free(p);
}
void search(){
    int key;
    cout<<"Enter Key to Search : ";
    cin>>key;
    struct BST *p=root;
    while(p!=NULL){
        if(p->data==key)
            break;
        if(p->data>key)
            p=p->lc;
        else
            p=p->rc;
    }
    if(p==NULL)
        cout<<"Key not found!"<<endl;
    else
        cout<<"Key "<<key<<" Found in BST "<<endl;
}
void maximum(){
    struct BST *p=root;
    if(p==NULL){
        cout<<"Empty BST tree!"<<endl;
        return;
    }
    while(p->rc!=NULL){
        p=p->rc;
    }
    cout<<"Maximum value is : "<<p->data<<endl;
}
void minimum(){
    struct BST *p=root;
    if(p==NULL){
        cout<<"Empty BST tree!"<<endl;
        return;
    }
    while(p->lc!=NULL){
        p=p->lc;
    }
    cout<<"Minimum value is : "<<p->data<<endl;
}
int height(BST *p){
    int  lh=0,rh=0;
    if(p==NULL)
        return 0;
    lh=height(p->lc);
    rh=height(p->rc);
    return 1+max(lh,rh);
}
int main(){
    int x;
    while(1){
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Maximum"<<endl;
        cout<<"5. Minimum"<<endl;
        cout<<"6. Height"<<endl;
        cout<<"0. exit"<<endl;
        cin>>x;
        switch(x){
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: search();
                    break;
            case 4: maximum();
                    break;
            case 5: minimum();
                    break;
            case 6: cout<<"Height of BST : "<<height(root)<<endl;
                    break;
            case 0: exit(0);

            default: cout<<"Please enter correct value!"<<endl;
        }
    }
    return 0;
}
