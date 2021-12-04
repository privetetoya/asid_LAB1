#pragma once
#include <iostream>
using namespace std;

class List {

private:

    class node {
    public:
        int element = 0;
        node* next;//pointer to the next element
    };

    node* head;//pointer to the begin
    node* tail;//pointer to the end

public:

    //Constructor with parameter
    List(int elem) {
        //Filled in by one element
        node* current = new node;
        current->element = elem;
        head = current;
        tail = current;
    }
    //Constructor without parameter
    List() {
        //Empty list
        head = NULL;
        tail = NULL;
    }
    //Destructor 
    ~List() {
        clear();
    }

    //Inserting an item at the end of a list
    void push_back(int elem) {
        node* current = new node;
        if (head == NULL) {
            current->element = elem;
            head = current;
            tail = head;
        }
        else {
            current->element = elem;
            tail->next = current;
            tail = current;
        }
    }
    //Inserting an item at the beginning of a list
    void push_front(int elem) {
        node* current = new node;
        if (head != NULL) {
            current->next = head;
            head = current;
            current->element = elem;
        }
        else {
            current->element = elem;
            head = current;
            tail = head;
        }
    }
    //Deleting the last element
    void pop_back() {
        if (head == NULL) {            //Invalid argument
            throw invalid_argument("List is empty");
        }
        else {
            if (head->next == NULL) {
                pop_front();
            }
            else {
                node* current = head;
                while (current->next != NULL) {
                    tail = current;
                    current = current->next;
                }
                tail->next = NULL;
                delete current;
            }
        }
    }
    //Deleting the first element
    void pop_front() {
        if (head != NULL) {
            node* current = head;
            head = head->next;
            delete current;
            if (head == NULL)
                tail = head;
        }
        else {                                         //Invalid argument
            throw invalid_argument("List is empty");
        }
    }
    //Adding an element to the middle of a list
    void insert(int elem, size_t index) {
        if (isEmpty() == true) {
            throw out_of_range("Out of range");         //Out of range
        }
        else {
            if (index > get_size() - 1) {         //Out of range
                throw out_of_range("Out of range");
            }
            else {
                node* current = head;
                node* extracurrent = new node;
                extracurrent->element = elem;
                for (int i = 0; i < index - 1; i++)
                    current = current->next;
                extracurrent->next = current->next;
                current->next = extracurrent;
            }
        }
    }
    //Retrieving an element by index
    int at(size_t index) {
        if (index < get_size()) // If index is in List range
        {
            node* current = head; // Create temporary node
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->element;
        }
        else {
            throw out_of_range("Out of range");  //Out of range
        }
    }
    //Removing an element from the middle of a list
    void remove(size_t index) {
        if (index > get_size() - 1) {         //Out of range
            throw out_of_range("Out of range");
        }
        else {
            if (index == 0)
            {
                return pop_front();
            }
            else if (index == get_size() - 1)
            {
                return pop_back();
            }
            else {
                node* current = head;
                node* extracurrent;
                for (int i = 0; i < index - 1; i++)
                    current = current->next;
                extracurrent = current->next;
                current->next = extracurrent->next;
                delete extracurrent;
            }
        }
    }
    //Getting the size of the list
    int get_size() {
        size_t list_size = 0;
        node* current = head;
        while (current != NULL) {
            list_size++;
            current = current->next;
        }
        return list_size;
    }
    //Delete the entire list
    void clear() {
        node* current = head;
        while (head != NULL) {
            current = head;
            head = head->next;
            delete current;
        }
        tail = head;
    }

    void set(size_t index, int elem) {                      //Replacing a list element by index
        if (index > get_size() - 1) {         //Out of range
            throw out_of_range("Out of range");
        }
        else {
            node* current = head;
            for (int i = 0; i < index; i++)
                current = current->next;
            current->element = elem;
        }
    }
    //Checking for an empty list
    bool isEmpty() {
        bool empty = false;
        if (head == NULL) {
            empty = true;
        }
        return empty;
    }
    int find_last(List& const list) {
        bool flag = false;
        int last_entry = -1; int counter = -1; int check = 0;
        node* current = head;                // Create temporary node
        node* extracurrent = list.head;
        node* check_current; node* check_extracurrent;
        while (current != NULL) {
            if (extracurrent->element != current->element) {
                current = current->next;
                counter = counter++;
            }
            else {
                flag = true;
                check_current = current->next; check_extracurrent = extracurrent->next;
                check = 1;
                for (; (check_extracurrent != NULL) && (check_current != NULL);) {
                    if (check_current->element == check_extracurrent->element) {
                        flag = true;
                    }
                    check_current = check_current->next; check_extracurrent = check_extracurrent->next;
                    check = check++;
                }
                if ((check_extracurrent == NULL) && (check_current != NULL))  flag = true;
                if (flag) last_entry = counter + 1;
                current = check_current;
                counter = counter + check;
            }
        }
        if (last_entry == -1)
        {                                                          //Invalid argument
            throw invalid_argument("Not included");
        }
        else
            return last_entry;
    };
    // Output of List
    friend ostream& operator << (ostream& stream, const List& list);
};



ostream& operator << (ostream& stream, const List& list)
{
    List::node* current = list.head;
    while (current != NULL) {
        stream << current->element << " ";
        current = current->next;
    }
    return stream;
}