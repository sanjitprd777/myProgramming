#include                              <bits/stdc++.h>
#define                               ll long long int
#define                               pb push_back
#define                               mp make_pair
#define                               ff first
#define                               ss second
#define                               nil -10e+9
#define                               initial 0
#define                               waiting 1
#define                               visited 2
#define                               inf 1e+15
#define                               mx 400005
#define                               mxx 4000005
#define                               mod 1000000007
#define                               pr pair<ll,ll>
#define                               fr(i,p,q) for(int i=p;i<q;++i)
#define                               frr(i,p,q) for(int i=p;i<=q;++i)
#define                               mem(a,b) memset(a,b,sizeof(a))
#define                               input freopen("input.txt", "r", stdin);
#define                               output freopen("output.txt", "w", stdout);
using namespace std;

ll tree[mx],arr[mx];
bool mark[mx];

void push(ll v){
	if(mark[v]){
		tree[2*v]=tree[2*v+1]=tree[v];
		mark[v]=false;
		mark[2*v]=mark[2*v+1]=true;
	}
}
void build_tree(ll v,ll tl,ll tr){
	if(tl==tr)
		tree[v]=arr[tl];
	else{
		tree[v]=0;
		mark[v]=false;
		ll tm=(tl+tr)/2;
		build_tree(2*v,tl,tm);
		build_tree(2*v+1,tm+1,tr);
	}
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll val){
	if(l>r)
		return;
	if(tl==l&&tr==r){
		tree[v]=val;
		mark[v]=true;
	}
	else{
		push(v);
		ll tm=(tl+tr)/2;
		update(2*v,tl,tm,l,min(tm,r),val);
		update(2*v+1,tm+1,tr,max(l,tm+1),r,val);
	}
}

ll query(ll v,ll tl,ll tr,ll pos){
	if(tl==tr)
		return tree[v];
	else{
		push(v);
		ll tm=(tl+tr)/2;
		if(pos<=tm)
			return query(2*v,tl,tm,pos);
		else
			return query(2*v+1,tm+1,tr,pos);
	}
}

int main(){

   	// ios_base::sync_with_stdio(false);
    // input;
    // Must change array size before submitting code
	
	ll n;
	cin>>n;

	frr(i,1,n)
		cin>>arr[i];

	build_tree(1,1,n);
    
    ll q,type;
    cin>>q;

    while(q--){
    	cin>>type;

    	if(type==1){
    		// assign;
    		ll l,r,val;
    		cin>>l>>r>>val;
    		update(1,1,n,l,r,val);
    	}
    	else{
    		// find
    		ll pos;
    		cin>>pos;
    		cout<<query(1,1,n,pos)<<endl;
    	}

    }
    return 0;
}