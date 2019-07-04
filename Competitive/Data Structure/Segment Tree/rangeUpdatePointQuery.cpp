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

void build_tree(ll v,ll tl,ll tr){
	if(tl==tr)
		tree[v]=arr[tl];
	else{
		ll tm=(tl+tr)/2;
		build_tree(2*v,tl,tm);
		build_tree(2*v+1,tm+1,tr);
		tree[v]=0;
	}
}

void update_tree(ll v,ll tl,ll tr,ll l,ll r,ll val){
	if(l>r)
		return;
	if(tl==l&&tr==r)
		tree[v]+=val;
	else{
		ll tm=(tl+tr)/2;
		update_tree(2*v,tl,tm,l,min(tm,r),val);
		update_tree(2*v+1,tm+1,tr,max(tm+1,l),r,val);
	}
}

ll query(ll v,ll tl,ll tr,ll pos){
	if(tl==tr)
		return tree[v];
	ll tm=(tl+tr)/2;
	if(pos<=tm)
		return tree[v]+query(2*v,tl,tm,pos);
	return tree[v]+query(2*v+1,tm+1,tr,pos);
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
			// update
			ll l,r,val;
			cin>>l>>r>>val;
			update_tree(1,1,n,l,r,val);
		}
		else{
			// query
			ll pos;
			cin>>pos;
			cout<<query(1,1,n,pos)<<endl;
		}
	
	}
    
    return 0;
}