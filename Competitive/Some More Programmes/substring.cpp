
#include<bits/stdc++.h>
using namespace std;

vector< string > input;

int lcp(string x , string y){
	int res = 0;
	while(res < x.size() && res < y.size() && x[res] == y[res]) ++res;
	return res;
}

int main(){
               cin.sync_with_stdio(false);
               int T;
               cin >> T;
               while(T--){
               	        string x;
               	        cin >> x;
               	        input.clear();
               	        for(int i = 0 ; i < x.size() ; ++i )
               	        input.push_back(x.substr(i));
               	        sort(input.begin() , input.end());
               	        int rank = input[0].size();
               	        for(int i = 1 ; i < input.size() && input[i - 1] != x; ++i)
               	        	rank += (input[i].size() - lcp(input[i - 1] , input[i]));
               	        cout << rank << endl;
               }
}
