#include <bits/stdc++.h>
using namespace std;
void heapify_up(vector<int> &v,int hsize){
    int i=hsize,par,k=v[hsize];
    par=i/2;
    while(k>v[par]){
        v[i]=v[par];
        i=par;
        par=i/2;
    }
    v[i]=k;
}
void insert_into_heap(vector<int> &v){
    int data;
    cin>>data;
    int hsize=v.size();
    v.push_back(data);
    heapify_up(v,hsize);
}
void heapify_down(vector<int> &v,int hsize,int pos=1){
    int lchild=2*pos,rchild=lchild+1;
    int num=v[pos];
    while(rchild<=hsize){
        if(num>=v[lchild]&&num>=v[rchild])
            break;
        else if(v[rchild]>v[lchild]){
            v[pos]=v[rchild];
            pos=rchild;
        }
        else{
            v[pos]=v[lchild];
            pos=lchild;
        }
        lchild=2*pos;
        rchild=lchild+1;
    }
    if(lchild==hsize&&num<v[lchild]){
        v[pos]=v[lchild];
        pos=lchild;
    }
    v[pos]=num;
}
void delete_from_heap(vector<int> &v){
    int hsize=v.size()-1;
    if(hsize==0){
        cout<<"Empty heap"<<endl;
        return;
    }
    int root=v[1];
    v[1]=v[hsize];
    hsize--;
    v.pop_back();
    heapify_down(v,hsize);
    cout<<"Highest element "<<root<<endl;
}
void display_heap(vector<int> &v){
    for(int i=1;i<v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
}
void build_heap(vector<int> &v){
    int hsize=v.size()-1;
    for(int i=hsize/2;i>0;--i){
        heapify_down(v,hsize,i);
    }
}
int main(){
    vector<int> v;
    v.push_back(9999);
    int x;
    while(1){
        cout<<"1. Insert into heap"<<endl;
        cout<<"2. Delete from heap"<<endl;
        cout<<"3. Display heap"<<endl;
        cout<<"4. Build heap"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>x;
        switch(x){
            case 1: insert_into_heap(v);
                    break;
            case 2: delete_from_heap(v);
                    break;
            case 3: display_heap(v);
                    break;
            case 4: build_heap(v);
                    break;
            case 5: exit(0);
                    break;
        }
    }
    return 0;
}
