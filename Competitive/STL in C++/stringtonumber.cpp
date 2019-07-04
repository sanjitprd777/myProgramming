#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    string src;
    int dst;
    src="12345";
    dst=atoi(src.c_str());
    cout<<"String 12345 to Number : "<<dst<<endl;
    cout<<"Some operation to check : ";
    cout<<"dst * 5 = "<<dst*5<<endl;
    next_permutation(src.begin(),src.end());
    dst=atoi(src.c_str());
    cout<<"String 12345 to Number : "<<dst<<endl;
    cout<<"Some operation to check : ";
    cout<<"dst * 5 = "<<dst*5<<endl;
    return 0;
}
