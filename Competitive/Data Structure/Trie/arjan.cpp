// Sanjit_Prasad
#include <bits/stdc++.h>
#define db double
#define ff first
#define ss second
#define initial 0
#define waiting 1
#define visited 2
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

const int mx=2e5+1;

struct node{
    int data;
    map<char, node*> child;
};

typedef node* pnode;

pnode root=new node;

void insert(string &s)
{
    int n=s.size();
    pnode cur=root;
    for(int i=0; i<n; ++i){
        if(!cur.child.count(s[i]))  cur.child[s[i]]=new node;
        cur=cur.child[s[i]];
    }
}

int main(){

   	// input;
   	ios_base::sync_with_stdio(false);    
	// Please change array size before submission!
	string s;
	cin>>s;
	
	insert(s);
    
    return 0;
}
