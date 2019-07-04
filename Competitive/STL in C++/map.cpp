#include <bits/stdc++.h>
#include <map>
//map automatically stores data in ascending order of key.
//index can be of any type including string.
//to access elements of map we use iterator.
//to insert element we use insert function along with pair method.
using namespace std;
int main(){
    map <int,string> student;
    student[100]="sanjit";
    student[230]="sahil";
    student[1000]="hello";
    student[490]="shashank";
    student.insert(make_pair(500,"sujeet"));
    map <int,string>::iterator i=student.begin();   //Iterator i is a pointer.
    while(i!=student.end()){
        cout<<i->first<<" "<<i->second<<endl;
        ++i;
    }
    cout<<student.size()<<endl;
    cout<<student.at(100)<<endl; //RETURN element at index.
    student.clear();
    if(student.empty())
        cout<<"MAP student is empty"<<endl;
    else
        cout<<"Map student has still some elements"<<endl;
    cout<<"Size of map STUDENT : "<<student.size()<<endl;
    //copy map
    map <int,string> temp(student.begin(),student.end());

    temp.erase(1000);//will erase 1000 index value;
    temp.count(100);
    temp.find(490);
    return 0;
}
