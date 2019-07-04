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

pr tree[mx];
ll arr[mx];

pr combine(pr p1,pr p2){
	if(p1.ff>p2.ff)
		return p1;
	if(p1.ff<p2.ff)
		return p2;
	return mp(p1.ff,p1.ss+p2.ss);
}

void build_tree(ll v,ll tl,ll tr){
	if(tl==tr)
		tree[v]=mp(arr[tl],1);
	else{
		ll tm=(tl+tr)/2;
		build_tree(2*v,tl,tm);
		build_tree(2*v+1,tm+1,tr);
		tree[v]=combine(tree[2*v],tree[2*v+1]);
	}
}

void update(ll v,ll tl,ll tr,ll pos,ll val){
	if(tl==tr)
		tree[v]=mp(val,1);
	else{
		ll tm=(tl+tr)/2;
		if(pos<=tm)
			update(2*v,tl,tm,pos,val);
		else
			update(2*v+1,tm+1,tr,pos,val);
		tree[v]=combine(tree[2*v],tree[2*v+1]);
	}
}

pr query(ll v,ll tl,ll tr,ll l,ll r){
	if(l>r)
		return mp(0,0);
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

	ll q,type;
	cin>>q;

	while(q--){
		cin>>type;
		if(type==1){
			// update
			ll pos,val;
			pos++;
			cin>>pos>>val;
			update(1,1,n,pos,val);
		}
		else if(type==2){
			// query
			ll l,r;
			cin>>l>>r;
			l++;	r++;
			pr p=query(1,1,n,l,r);
			cout<<p.ff<<" "<<p.ss<<endl;
		}
	}

    return 0;
}