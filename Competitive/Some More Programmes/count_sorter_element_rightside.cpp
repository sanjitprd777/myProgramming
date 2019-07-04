//this programe is for distinct data...
#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ull unsigned long long int
#define mod 1000000007  //1000000009
#define stop return 0;
using namespace std;
struct node{
    ll data;
    struct node *left,*right;
    ll size,height;
};
struct node *root=NULL;
struct node* create_node(ll data){
    struct node *temp;
    temp=new(node);
    temp->data=data;
    temp->size=1;
    temp->height=1;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
ll heightt(struct node *temp){
    if(temp==NULL)
        return 0;
    return temp->height;
}
ll balance(struct node *temp){
    if(temp==NULL)
        return 0;
    return heightt(temp->left)-heightt(temp->right);
}
ll size_left(struct node *temp){
    if(temp==NULL)
        return 0;
    return temp->size;
}
struct node* rotate_left(struct node *a){
    struct node *b;
    b=a->right;
    a->right=b->left;
    b->left=a;
    a->height=max(heightt(a->left),heightt(a->right))+1;
    b->height=max(heightt(b->left),heightt(b->right))+1;
    a->size=size_left(a->left)+size_left(a->right)+1;
    b->size=size_left(b->left)+size_left(b->right)+1;
    return b;
};
struct node* rotate_right(struct node *a){
    struct node *b;
    b=a->left;
    a->left=b->right;
    b->right=a;
    a->height=max(heightt(a->left),heightt(a->right))+1;
    b->height=max(heightt(b->left),heightt(b->right))+1;
    a->size=size_left(a->left)+size_left(a->right)+1;
    b->size=size_left(b->left)+size_left(b->right)+1;
    return b;
};
struct node * insert_avl(ll data,struct node *root,ll &count){

    if(root==NULL)
        return create_node(data);
    else if(data<root->data)// note if repeated elements are allowed than (data<=root->data)
        root->left=insert_avl(data,root->left,count);
    else{
        count+=size_left(root->left)+1;
        root->right=insert_avl(data,root->right,count);
    }
    root->height=max(heightt(root->left),heightt(root->right))+1;
    root->size=size_left(root->left)+size_left(root->right)+1;
    ll bal=balance(root);

    if(bal>1&&data<root->left->data)
        return rotate_right(root);
    if(bal>1&&data>root->left->data){
        root->left=rotate_left(root->left);
        return rotate_right(root);
    }
    if(bal<-1&&data>root->right->data)
        return rotate_left(root);
    if(bal<-1&&data<root->right->data){
        root->right=rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}
int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--){
        root=NULL;
        ll n,count,i,k;
        cin>>n;
        ll arr[n],ans[n];
        for(i=0;i<n;++i)
            cin>>arr[i];
        for(i=n-1;i>=0;--i){
            count=0;
            root=insert_avl(arr[i],root,count);
            ans[i]=count;
        }
        for(i=0;i<n;++i)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    stop;
}

