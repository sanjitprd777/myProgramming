#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
void swap(char *x,char *y){
    char ch=*x;
    *x=*y;
    *y=ch;
}
void permutation(char *s,int i,int n){
    int j;
    if(n==i)
        cout<<s<<endl;
    else{
        for(j=i;j<=n;++j){
            swap(s+i,s+j);
            permutation(s,i+1,n);
            swap(s+i,s+j);
        }
    }

}
int main()
{
    char s[]="1234";
    //Passing three arguments s  ,  0  ,  l - 1.
    permutation(s,0,strlen(s)-1);
    return 0;
}

