/*
//short cut code;
#include <bits/stdc++.h>
#define ll long int
using namespace std;
//function check leap year
ll month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};

int dayofweek(ll y,ll m,ll d){
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll y,m,d;
        cin>>y>>m>>d;
        cout<<week[dayofweek(y,m,d)]<<endl;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
#define ll long int
using namespace std;
//function check leap year
ll month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
string leap(ll n){
    string ans="false";
    if(n%4==0)  ans="true";
    if(n%100==0)  ans="false";
    if(n%400==0)  ans="true";
    return ans;
}
ll dayinmonth(ll i,ll y){
    int d=month[i];
    if(i==2&&leap(y)=="true")
        d++;
    return d;
}
ll dayofyear(ll y,ll m,ll d){
    int c=0;
    for(ll i=1;i<m;++i)
        c+=dayinmonth(i,y);
    c+=d;
    return c;
}
int dayofweek(ll y,ll m,ll d){
    y--;  //leaving the same year .
    y=y%400; //since Gregorian Calender repeats after 400 yrs.
    ll lp=y/4-y/100+y/400;  //leap year passed
    ll ry=y-lp;  //regular year passed
    ll w;
    w=ry;  //since regular year has 1 odd day;
    w=w+2*lp;  //since leap year has 2 odd day;
    w=w+dayofyear(y+1,m,d);
    w%=7;
    return w;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll y,m,d;
        cin>>y>>m>>d;
        cout<<week[dayofweek(y,m,d)]<<endl;
    }
    return 0;
}
