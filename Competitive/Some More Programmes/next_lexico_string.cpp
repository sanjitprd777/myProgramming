/* Algorithm:
1. Find the highest index i such that s[i] < s[i+1]. If no such index exists, the permutation is the last permutation.
2. Find the highest index j > i such that s[j] > s[i]. Such a j must exist, since i+1 is such an index.
3. Swap s[i] with s[j].
4. Reverse the order of all of the elements after index i till the last element.
*/
#include <bits/stdc++.h>
using namespace std;
int bsearch(string &s,int l,int r,int key){
      int index=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(s[mid]<=key)
                r=mid-1;
            else{
                l=mid+1;
                if(index=-1||s[index]<=s[mid])
                    index=mid;
            }
        }
    return index;
}
void swap(char *s,char *t){
    if(*s==*t)
        return;
    *s^=*t;
    *t^=*s;
    *s^=*t;
}
bool nxtp(string &s){
    int l=s.length() , i;
    i=l-2;
    while(i>=0&&s[i]>=s[i+1])
        --i;
    if(i<0)
        return false;
    else{
        int index=bsearch(s,i+1,l-1,s[i]);
        swap(&s[i],&s[index]);
       reverse(s.begin()+i+1,s.end());
        return true;
    }
}

int main(){
    long int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool val=nxtp(s);
        if(val==true)
            cout<<s<<endl;
        else
            cout<<"no answer"<<endl;
    }
    return 0;
}
