//undirected graph
#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define rep2(j,p,q) for(j=p;j<q;++j)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define REP2(j,p,q) for(j=p;j<=q;++j)
#define MOD 1000000007
#define stop return 0
#define MAX 1001
#define nil -1
#define infinity 99999
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
ll label[MAX];
enum {initial=1,waiting,visited};
ll graph[MAX][MAX]={0};
ll state[MAX];
ll q[infinity],front=-1,rear=-1;
ll isFull(){
    if(rear==MAX-1)
        return 1;
    return 0;
}
ll isEmpty(){
    if(front==-1||front>rear)
        return 1;
    return 0;
}
void insert_queue(ll v){
    if(isFull()){
        cout<<"Queue overflow"<<endl;
        exit(0);
    }
    if(front==-1)
        front=0;
    rear+=1;
    q[rear]=v;
}
ll delete_queue(){
    if(isEmpty()){
        cout<<"Queue underflow"<<endl;
        exit(0);
    }
    ll data=q[front];
    front++;
    return data;
}
void create_graph(ll node,ll edge){
    ll i,j,u,v;
    rep1(i,0,node)
        rep2(j,0,node)
            graph[i][j]=0;
    rep1(i,0,edge){
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
}
void bfs(ll v,ll node,ll component){
    ll i,vrt;
    insert_queue(v);
    state[v]=waiting;
    while(!isEmpty()){
        vrt=delete_queue();
        label[vrt]=component;
        state[vrt]=visited;
        rep1(i,0,node)
            if(graph[vrt][i]==1&&state[i]==initial){
                    insert_queue(i);
                    state[i]=waiting;
            }
    }
}
ll bfs_traversal(ll node){
    ll i,v,comp=0;
        rep1(i,0,node)
            state[i]=initial;
    rep1(i,0,node)
        if(state[i]==initial){
            comp++;
            bfs(i,node,comp);
        }
    return comp;
}
int main(){
    fast;
    ll i,node,u,v,edge;
    cin>>node>>edge;
    create_graph(node,edge);
    ll comp=bfs_traversal(node);
    rep1(i,0,node)
        cout<<i<<" "<<label[i]<<endl;
    cout<<"Total Spanning Tree is : "<<comp<<endl;
    stop;
}

