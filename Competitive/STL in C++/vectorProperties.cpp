// A C++ program to demonstrate working of sort(),
// reverse()
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> vect;
    for(int i=0;i<10;++i)
        vect.push_back(10*(i+1));
    cout<<vect.size()<<endl;
    cout << "Vector is: ";
    for (int i=0; i<vect.size(); i++)
        cout << vect[i] << " ";
    cout<<endl;

    sort(vect.begin(), vect.end());
    if (std::binary_search (vect.begin(), vect.end(), 50)) //50 is the element to be searched.
            std::cout << "found!\n";
    else
            std::cout << "not found.\n";

    // Reversing the Vector
    reverse(vect.begin(), vect.end());
    cout << "\nVector after reversing is: ";
    for (int i=0; i<vect.size(); i++)
        cout << vect.at(i) << " ";
    cout<<endl;

    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end())<<endl;

    // to insert new element.
    vector<int>:: iterator i=vect.begin();
    vect.insert(i+3,50);// insert 50 at position 4 i.e after 3.

    //to delete any element at given position.
    vect.erase(i+1);
    // to erase vector vect.erase(vect.begin(),vect.end()); or vect.clear();
    // to remove duplicate elements vect.erase(unique(vect.begin(),vect.end())vect.end());
    // next_permutation(vect.begin(),vect.end()); prev_permutation(same);
    //"IMPORTANT" distance(first_iterator,desired_position) it returns the index of desired position element.
    cout<<"count of 50 is : "<<count(vect.begin(),vect.end(),50)<<endl;//gives count of 50 in the vector.

    for (int i=0; i<vect.size(); i++)
        cout << vect[i] << " ";

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0)<<endl;//here we can change "0" to any value it will be added to final answer.
    return 0;
}
