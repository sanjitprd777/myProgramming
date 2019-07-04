#include <bits/stdc++.h>
#include <list>
using namespace std;
//list is somewhat different from vector.
// list is doubly_linked_list so use iterator to traverse
//function for printing the elements in a list
// in list we can push data in front also
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{

    list <int> gqlist1, gqlist2;


    for (int i = 0; i < 10; ++i)
    {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }
    cout << "\nList 1 (gqlist1) is : ";
    showlist(gqlist1);

    cout << "\nList 2 (gqlist2) is : ";
    showlist(gqlist2);

    //to merge both list gqlist1.merge(gqlist2);
    //To reverse - gqlist1.reverse();   To sort - gqlist2.sort();

    // to insert element
    list <int>:: iterator it=gqlist1.begin();
    advance(it,3);//advance iterator position
    gqlist1.emplace_front(7777);
    gqlist1.emplace_back(9999);
    gqlist1.emplace(it,3333);

    cout<<"List 1"<<endl;
    showlist(gqlist1);
    cout<<endl;

    // using remove_if() to remove odd elements
    //if condition true element will be deleted.
    gqlist1.remove_if([](int x){return x%2!=0;});
    //
    gqlist1.remove(2); //removes all occurence of 2 from list.
    gqlist1.unique(); //removes duplicate elements.

    gqlist1.swap(gqlist2); //swap both list.

    gqlist1.splice(gqlist2.begin(),gqlist2);//copy gqlist2 in gqlist1
    showlist(gqlist1);

    return 0;

}
