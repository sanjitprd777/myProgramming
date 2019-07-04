#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	long long int ans,a,b,cc,t;
	cin>>t;
	while(t--){
	    cin>>a>>b>>cc;
	    long long int i,k,carry=0,c,j;
	    vector <int> aa,bb;
	    int mul[100]={0};
	    while(a>0){
            aa.push_back(a%10);
            a/=10;
	    }
        while(b>0){
            bb.push_back(b%10);
            b/=10;
        }
        for(i=0;i<aa.size();++i){
            carry=0;
            k=i;
            for(j=0;j<bb.size();++j){
                c=aa[i]*bb[j]+carry;
                if(i>0)
                    c+=mul[k];
                carry=c/10;
                c%=10;
                mul[k++]=c;
            }
            if(carry)
                mul[k++]=carry;
        }
        ans=0;
        for(i=k-1;i>=0;--i)
            ans=(ans*10+mul[i])%cc;
        cout<<ans<<endl;
	}
	return 0;
}

