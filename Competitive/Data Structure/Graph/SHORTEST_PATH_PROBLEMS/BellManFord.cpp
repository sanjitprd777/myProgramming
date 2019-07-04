#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define stop return 0
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define getchar_unlocked getchar
#define pb push_back
#define nil -1
#define initial 0
#define waiting 1
#define visited 2
#define inf 4e+9
using namespace std;
const ll N=8;
vector<ll> v[N],v2[N];
ll x,y,i,j,w,temp,src,flag,cnt=0;
ll prd[N],dis[N],status[N];
ll Bellmanford(ll src){
    rep1(i,0,N){
        prd[i]=nil;
        dis[i]=inf;
        status[i]=initial;
    }
    queue<ll> q;
    q.push(src);
    dis[src]=0;
    status[i]=waiting;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==src){
            ++cnt;
            if(cnt==N)
                return -1;
        }
        status[temp]=initial;
        rep1(i,0,v[temp].size()){
            if(dis[v[temp][i]]>dis[temp]+v2[temp][i]){
                dis[v[temp][i]]=dis[temp]+v2[temp][i];
                prd[v[temp][i]]=temp;
                if(status[v[temp][i]]==initial){
                    q.push(v[temp][i]);
                    status[v[temp][i]]=waiting;
                }
            }
        }
    }
    return 1;
}
int main(){
    cout<<"Enter the edges and weight and -1 -1 -1 to stop"<<endl;
    while(1){
        cin>>x>>y>>w;
        if(x==-1&&y==-1&&w==-1)
            break;
        v[x].push_back(y);
        v2[x].push_back(w);
    }
    cout<<"Enter source vertex : "<<endl;
    cin>>src;
    flag=Bellmanford(src);
    if(flag==-1)
        cout<<"Negative cycle exist"<<endl;
    else{
        cout<<"Distance of all vertices from source vertex is : "<<endl;
        rep1(i,0,N){
            if(prd[i]!=nil)
                cout<<dis[i]<<endl;
        }
    }
    return 0;
}
