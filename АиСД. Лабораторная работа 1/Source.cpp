#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    List New_List;
    cout << "Let's create a List ";
    List List(2);
    cout << List << endl;
    cout << "Inserting one elements at the begin of a list ";
    List.push_front(1);
    cout << List << endl;
    cout << "Inserting some elements at the end of a list ";
    List.push_back(3);
    List.push_back(4);
    cout << List << endl;
    cout << "Delete an element at the beginning and end ";
    List.pop_back();
    List.pop_front();
    cout << List << endl;
    cout << "Let's try to insert element in the middle " << endl;
    try
    {
        List.insert(100, 100);
    }
    catch (const out_of_range error)
    {
        cout << error.what() << endl;
    }
    cout << "Let's try again ";
    List.insert(1, 1);
    cout << List << endl;
    cout << "Let's try to find the value of the first element ";
    cout << List.at(0) << endl;
    cout << "Delete second element ";
    List.remove(1);
    cout << List << endl;
    cout << "Let's try to find out the size of the list " << List.get_size() << endl;
    cout << "Let's clean up the List ";
    List.clear();
    cout << List << endl << endl;
    cout << "Let's fill in List ";
    List.push_back(1);
    List.push_back(2);
    cout << List << endl;
    cout << "Let's swap the second element  ";
    List.set(1, 3);
    cout << List << endl;
    cout << "Let's check for a blank list ";
    List.isEmpty();
    cout << List << endl;
    cout << "Let's create a new list: " << endl;
    New_List.push_front(1);
    New_List.push_back(2);
    cout << New_List << endl;
    cout << "Find the index of the last occurrence in the List: \n";
    try {
        cout << List.find_last(New_List) << endl;
    }
    catch (const invalid_argument error) {
        cout << error.what() << endl;
    }
    List.push_back(1);
    List.push_back(2);
    cout << "Add elements to the end of an existing List: " << endl;
    cout << List << endl;
    cout << "Find the index of the last occurrence in the List: " << endl;
    try {
        cout << List.find_last(New_List);
    }
    catch (const invalid_argument error) {
        cout << error.what();
    }
    return 0;
}