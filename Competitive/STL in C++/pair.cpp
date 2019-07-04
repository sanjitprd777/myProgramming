#include <bits/stdc++.h>
using namespace std;
class student{
private:
    string name;
    int age;
public:
    void setdata(string ss,int a){
        name=ss;
        age=a;
    }
    void showdata(){
        cout<<name<<" "<<age;
    }
};
int main(){
    pair <int,float> p1,p4;
    p1=make_pair(5,5.5);
    p4=make_pair(5,5.5);
    pair <char,int> p3;
    p3=make_pair('a',999);
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p3.first<<" "<<p3.second<<endl;
    student s;
    s.setdata("Sanjit Prasad",20);
    pair <int,student> p2;
    p2=make_pair(1,s);
    cout<<p2.first<<" "<<endl;
    student s2=p2.second;
    s2.showdata();
    //here we can also compare two pairs using ==,<=,>=,!=,>,<. Remember pair need to be of same type.
    if(p1==p4)
        cout<<endl<<"Equal Pair";
    else
        cout<<endl<<"Unequal Pair";
    cout<<endl;
//  another same class is "tuple" for storing 3 datas;
    tuple <int,int,string> t;
    t=make_tuple(4,4,"tupleprograme");
    cout<<get<0>(t)<<" ";
    cout<<get<1>(t)<<" ";
    cout<<get<2>(t);
 return 0;
}
