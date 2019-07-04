
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

//The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

struct Node* create(int data){  // Create New Node
    struct Node* t;
    t=new(Node);
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    t->height=1;
    return t;
}
int height(Node* t){  // Return height of Node
    if(t==NULL)
        return 0;
    return t->height;
}
int balance(Node* t){
    if(t==NULL)
        return 0;
    return height(t->left)-height(t->right);
}
struct Node* rotate_left(struct Node* a){
    struct Node *b;
    b=a->right;
    a->right=b->left;
    b->left=a;
    a->height=1+max(height(a->left),height(a->right));
    b->height=1+max(height(b->left),height(b->right));
    return b;
}
struct Node* rotate_right(struct Node* a){
    struct Node *b;
    b=a->left;
    a->left=b->right;
    b->right=a;
    a->height=1+max(height(a->left),height(a->right));
    b->height=1+max(height(b->left),height(b->right));
    return b;
}
/*You are required to complete this method */
Node* insertToAVL( Node* node, int data)
{
    if(node==NULL)
        return create(data);
    else if(data<node->data)
        node->left=insertToAVL(node->left,data);
    else if(data>node->data)
        node->right=insertToAVL(node->right,data);
    // height of new node...
    node->height=1+max(height(node->left),height(node->right));
    // Balance of new node...
    int bal=balance(node);
    // Checking rotations
    // LL rotation
    if(bal>1&&data<node->left->data)
        return rotate_right(node);
    // LR rotation
    if(bal>1&&data>node->left->data){
        node->left=rotate_left(node->left);
        return rotate_right(node);
    }
    // RR rotation
    if(bal<-1&&data>node->right->data)
        return rotate_left(node);
    // RL rotation
    if(bal<-1&&data<node->right->data){
        node->right=rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}
