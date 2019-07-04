
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int R,C,r,c;
vector <string> G,P;
bool f(int x,int y){
    int i,j,ii,jj;
    for(i=0;i<r;++i)
    for(j=0;j<c;++j){
        ii=i+x;  jj=j+y;
        if(ii>=R||jj>=C)
            return false;
        else if(G[ii][jj]!=P[i][j])
            return false;
        else
            continue;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int j,i;
        bool check=false;
        cin>>R>>C;
        G= vector <string> (R);
        for(i=0;i<R;++i)
            cin>>G[i];
        cin>>r>>c;
        P= vector <string> (r);
        for(i=0;i<r;++i)
            cin>>P[i];
        for(i=0;i<R;++i){
            for(j=0;j<C;++j){
                check=f(i,j);
                if(check)
                    break;
            }
            if(check)
                break;
        }
        cout<<(check?"YES":"NO")<<endl;
    }

    return 0;
}
