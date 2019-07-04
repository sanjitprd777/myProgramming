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
#define MAX 100
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
enum {initial=1,waiting,visited};
struct node{
    int nod;
};
struct arc{
    int val=0;
};
struct graph{
    struct node nodes[MAX];
    struct arc arcs[MAX][MAX];
    struct node state[MAX];
};
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
        exit(0);
    }
    if(front==-1)
        front=0;
    rear+=1;
    q[rear]=v;
}
ll delete_queue(){
    if(isEmpty()){
        exit(0);
    }
    ll data=q[front];
    front++;
    return data;
}
struct graph create_graph(struct graph g,ll node,ll edge){
    ll i,u,v;
    rep1(i,0,edge){
        cin>>u>>v;
        g.arcs[u][v].val=1;
        g.arcs[v][u].val=1;
    }
    return g;
}
void bfs(struct graph g,ll v,ll node){
    ll i,vrt;
    insert_queue(v);
    while(!isEmpty()){
        vrt=q[front]; //vrt=delete_queue();
        cout<<vrt<<" ";
        rep1(i,0,node)
            if(g.arcs[vrt][i].val==1&&g.state[i].nod==initial){
                    insert_queue(i);
                    g.state[i].nod=waiting;
            }
        vrt=delete_queue();
        g.state[vrt].nod=visited;
    }
}
void bfs_traversal(struct graph g,ll node){
    ll i,v;
        rep1(i,0,node)
            g.state[i].nod=initial;
    cout<<"Enter a start Vertex"<<endl;
    cin>>v;
    //some time it might be possible in case of (directed graph only) that all vertex are not visited so in that case a simple modification is required
    //  for(i=0;i<node;++i)
    //     if(g.state[i].nod==initial)
    //        bfs(g,i,node);
    bfs(g,v,node);
}
int main(){
    fast;
    struct graph g;
    ll node,edge;
    cout<<"Enter nodes and edges of the graph"<<endl;
    cin>>node>>edge;
    cout<<"Enter all the edges"<<endl;
    g=create_graph(g,node,edge);
    cout<<"BFS traversal of graph"<<endl;
    bfs_traversal(g,node);
    stop;
}

/*
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
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
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
        exit(0);
    }
    if(front==-1)
        front=0;
    rear+=1;
    q[rear]=v;
}
ll delete_queue(){
    if(isEmpty()){
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
    }
}
void bfs(ll v,ll node){
    ll i,vrt;
    insert_queue(v);
    while(!isEmpty()){
        vrt=q[front]; //vrt=delete_queue();
        cout<<vrt<<" ";
        rep1(i,0,node)
            if(graph[vrt][i]==1&&state[i]==initial){
                    insert_queue(i);
                    state[i]=waiting;
            }
        vrt=delete_queue();
        state[vrt]=visited;
    }
}
void bfs_traversal(ll node){
    ll i,v;
        rep1(i,0,node)
            state[i]=initial;
    cout<<"Enter a start Vertex"<<endl;
    cin>>v;
    //some time it might be possible in case of (directed graph only) that all vertex are not visited so in that case a simple modification is required
    //  for(i=0;i<node;++i)
    //     if(state[i]==initial)
    //        bfs(i,node);
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
*/
