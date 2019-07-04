// a simple program to update index value or return prefix sum.
#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep(i,p,q) for(i=p;i<q;++i)
#define REP(i,p,q) for(i=p;i<=q;++i)
#define MOD 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define stop return 0
#define getchar_unlocked getchar
using namespace std;
int sI(){
        register int c = getchar();
        bool flag = true;
        if(c=='-'){
            flag =false;
            c = getchar_unlocked();
        }
        int n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        if(flag){
            return n;
        }
        else{
            return n*-1;
        }
}
long long sLL(){
        register int c = getchar_unlocked();
        bool flag = true;
        if(c=='-'){
            flag =false;
            c = getchar_unlocked();
        }
        long long n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        if(flag){
            return n;
        }
        else{
            return n*-1;
        }
}
void s1(){
        register int c = getchar_unlocked();
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() );
}

void update(ll bit[],ll n,ll x,ll val){
    while(x<=n){
        bit[x]+=val;
        x+=x&(-x);
    }
}
ll query(ll bit[],ll x){
    ll val=0;
    while(x>0){
        val+=bit[x];
        x-=x&(-x);
    }
    return val;
}
int main()
{
    fast;
        ll n,i,x,q,a,b;
        cin>>n>>q;
        ll arr[n],bit[n+1]={0};
        rep(i,0,n)
            cin>>arr[i];
        rep(i,0,n)
            update(bit,n+1,i+1,arr[i]);
        while(q--){
            cin>>x>>a>>b;
            a++; b++;
            if(x==1){
                //return csum[b]-csum[a-1];
                cout<<query(bit,b)-query(bit,a-1)<<endl;
            }
            else{
                update(bit,n+1,a,b-1);
            }
        }
    stop;
}
