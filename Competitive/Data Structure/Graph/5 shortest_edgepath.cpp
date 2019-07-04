//directed graph
#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define rep2(j,p,q) for(j=p;j<q;++j)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define REP2(j,p,q) for(j=p;j<=q;++j)
#define MOD 1000000007
#define stop return 0
#define MAX 100
#define nil -1
#define infinity 99999
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
ll predecesor[MAX];
ll dist[MAX];
enum {initial=1,waiting,visited};
ll graph[MAX][MAX]={0};
ll state[MAX];
ll q[MAX],front=-1,rear=-1;
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
        if(u<0||v<0||u>node||v>node){
            cout<<"invalid edge!"<<endl;
            --i;
        }
        graph[u][v]=1;
    }
}
void bfs(ll v,ll node){
    ll i,vrt;
    insert_queue(v);
    dist[v]=0;
    while(!isEmpty()){
        vrt=delete_queue();
        cout<<vrt<<" ";
        rep1(i,0,node)
            if(graph[vrt][i]==1&&state[i]==initial){
                    insert_queue(i);
                    state[i]=waiting;
                    predecesor[i]=vrt;
                    dist[i]=dist[vrt]+1;
            }
        state[vrt]=visited;
    }
    cout<<endl<<"Predecessor of all nodes and distance from given vertex is : "<<endl;
    cout<<"     Predecessor"<<setw(10)<<"Distance"<<endl;
    rep1(i,0,node)
        cout<<i<<setw(7)<<predecesor[i]<<setw(15)<<dist[i]<<endl;

}
void bfs_traversal(ll node){
    ll i,v;
        rep1(i,0,node){
            state[i]=initial;
            dist[i]=infinity;
            predecesor[i]=nil;
        }
    cout<<"Enter a start Vertex"<<endl;
    cin>>v;
    bfs(v,node);
}
int main(){
    fast;
    ll node,edge;
    cout<<"Enter nodes and edges of the graph"<<endl;
    cin>>node>>edge;
    cout<<"Enter all the edges"<<endl;
    create_graph(node,edge);
    cout<<"BFS traversal of graph"<<endl;
    bfs_traversal(node);
    stop;
}
