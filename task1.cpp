// Muhammad Ubaid - 511364 - BSCS-15D
// Lab 04 - Task 1

#include <iostream>
using namespace std;

class List {
private:
    struct node {
        int data;
        node* next;
    };

    node* head;
    node* curr;

public:
    List() {
        head = nullptr;
    }

    void createThreeNodes(){
        node* first = new node;
        node* second = new node;
        node* third = new node;

        cout<<"Enter 1st data: ";
        cin>>first->data;

        cout<<"Enter 2nd data: ";
        cin>>second->data;

        cout<<"Enter 3rd data: ";
        cin>>third->data;

        first->next = second;
        second->next = third;
        third->next = nullptr;

        head = first;
    }

    void printList(){
        if(head==nullptr){
            cout<<"List is Empty!"<<endl;
            return;
        }

        curr = head;

        cout<<"The list is: ";
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;

    }

    void clearList(){
        curr = head;

        while(curr!=nullptr){
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = nullptr;

        cout<<"The list is cleared!"<<endl;
    }
};

int main(){
    List myList;
    //printing empty list
    myList.printList();

    //printing list with data filled
    myList.createThreeNodes();
    myList.printList();

    //clearing list
    myList.clearList();

    //printing list after clearing
    myList.printList();
    return 0;
}

