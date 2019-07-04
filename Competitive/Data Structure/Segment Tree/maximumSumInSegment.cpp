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

struct node
{
	ll sum,pre,suff,ans;
};

node tree[mx];
ll arr[mx];

node make(ll val){
	node res;
	res.sum=val;
	res.pre=res.suff=res.ans=max((ll)0,val);
	return res;
}

node combine(node l,node r){
	node res;
	res.sum=l.sum+r.sum;
	res.pre=max(l.pre,l.sum+r.pre);
	res.suff=max(r.suff,r.sum+l.suff);
	res.ans=max(max(l.ans,r.ans),l.suff+r.pre);
	return res;
}

void build_tree(ll v,ll tl,ll tr){
	if(tl==tr){
		tree[v]=make(arr[tl]);
	}
	else{
		ll tm=(tl+tr)/2;
		build_tree(2*v,tl,tm);
		build_tree(2*v+1,tm+1,tr);
		tree[v]=combine(tree[2*v],tree[2*v+1]);
	}
}

node query(ll v,ll tl,ll tr,ll l,ll r){
	if(l>r)
		return make(0);
	if(tl==l&&tr==r)
		return tree[v];
	else{
		ll tm=(tl+tr)/2;
		return combine(query(2*v,tl,tm,l,min(tm,r)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
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

	ll q;
	cin>>q;

	while(q--){
		ll l,r;
		cin>>l>>r;
		l++;	r++;
		cout<<query(1,1,n,l,r).ans<<endl;
	}
    return 0;
}