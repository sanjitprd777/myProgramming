#include <bits/stdc++.h>
#define ll long long int
#define ull long long int
#define rep1(i,p,q) for(i=p;i<q;++i)
#define rep2(j,p,q) for(j=p;j<q;++j)
#define REP1(i,p,q) for(i=p;i<=q;++i)
#define REP2(j,p,q) for(j=p;j<=q;++j)
#define MOD 1000000007
#define stop return 0
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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
ll solve(ll mid,vector<ll> odd,vector<ll> even){
    ll pos=0,i;
    rep1(i,0,odd.size())
        pos+=mid/odd[i];
    rep1(i,0,even.size())
        pos-=mid/even[i];
    return pos;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll p,i,j,val;
        //input prime
        cin>>p;
        ll prime[p];
        rep1(i,0,p)
            cin>>prime[i];
        vector<ll> v1,v2,v11,v22;
        v1.push_back(prime[p-1]);
        for(i=p-2;i>=0;--i){
            v11.clear(); v22.clear();

            for(j=0;j<v1.size();++j)
                v22.push_back(prime[i]*v1[j]);

            for(j=0;j<v2.size();++j)
                v11.push_back(prime[i]*v2[j]);

            v1.push_back(prime[i]);

            for(j=0;j<v11.size();++j)
                v1.push_back(v11[j]);

            for(j=0;j<v22.size();++j)
                v2.push_back(v22[j]);

        }
    /* USING MAP speed is optimized
    map<ll,ll> m1,m2;
        m1[prime[p-1]]++;
        for(i=p-2;i>=0;--i){
                map<ll,ll> m11,m22;
                for(auto it:m1){
                    v=(it.first*prime[i])%m;  k=it.second;
                    m22[v]+=k;
                }
                for(auto it:m2){
                    v=(it.first*prime[i])%m;  k=it.second;
                    m11[v]+=k;
                }
                m1[prime[i]]++;

                for(auto it:m11){
                    v=it.first; k=it.second;
                    m1[v]+=k;
                }
                for(auto it:m22){
                    v=it.first; k=it.second;
            m2[v]+=k;
        }
    }
    */
        ll high,mid,low,k,c;
        cin>>k;
        low=prime[0],high=prime[0]*k;
        while(high>=low){
            mid=(low+high)/2;
            c=solve(mid,v1,v2);
            if(c==k)
                break;
            else if(c>k)
                high=mid-1;
            else
                low=mid+1;
        }
        while(1){
            rep1(i,0,p)
                if(mid%prime[i]==0)
                    goto label;
            mid--;
        }
        label:
            cout<<mid<<endl;

    }
    return 0;
}

