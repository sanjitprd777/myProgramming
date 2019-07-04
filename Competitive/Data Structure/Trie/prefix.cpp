// Sanjit_Prasad
#include <bits/stdc++.h>
#define db double
#define ff first
#define ss second
#define initial 0
#define waiting 1
#define visited 2
#define mx 1000005
#define mxx 4000005
#define mod 1000000007
#define inf 1000000009
#define nil -1000000009
#define pb push_back
#define mp make_pair
#define pr pair<ll,ll>
#define ll long long int
#define ull unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define fr(i,p,q) for(int i=p; i<q ; ++i)
#define frr(i,p,q) for(int i=p; i<=q ; ++i)
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
ll power(ll a,ll b){ll aa=1;while(b){if(b&1){aa=aa*a;aa%=mod;}a=a*a;a%=mod;b/=2;}return aa;}
using namespace std;

ll trie[26][mx],ans[26][mx]={0},sz=0;
string s,type;

void insert(){
	ll v=0;
	fr(i,0,s.size()){
		ll c=s[i]-'a';
		if(trie[c][v]==-1){
			trie[c][v]=++sz;
		}
		ans[c][v]++;
		v=trie[c][v];
	}
}

ll query(){
	ll v=0,res=0;
	fr(i,0,s.size()){
		ll c=s[i]-'a';
		if(trie[c][v]!=-1){
			if(i==s.size()-1)
				res = ans[c][v];
			v=trie[c][v];
		}
		else
			break;
	}
	return res;
}

int main(){

   	// input;
   	ios_base::sync_with_stdio(false);    
	// Please change array size before submission!
	
	mem(trie,-1);

	ll n;
	cin>>n;
	while(n--){
		cin>>type>>s;
		if(type=="add")
			insert();
		else
			cout<<query()<<endl;
	}
    return 0;
}
