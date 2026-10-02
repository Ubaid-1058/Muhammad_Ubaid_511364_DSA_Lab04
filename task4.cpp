// Muhammad Ubaid - 511364 - BSCS-15D
// Lab 04 - Task 4

#include <iostream>
using namespace std;

class List {
private:
    struct node {
        int data;
        node* next;
    };

    node* head;

public:
    List() {
        head = nullptr;
    }

    void AddNode(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void InsertAtBeginning(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;
        head = newNode;
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearList() {
        node* curr = head;

        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = nullptr;
    }
};

int main() {
    List myList;

    cout << "Insert 20 at beginning:" << endl;
    myList.InsertAtBeginning(20);
    myList.PrintList();

    cout << "Insert 10 at beginning:" << endl;
    myList.InsertAtBeginning(10);
    myList.PrintList();

    cout << "Append 30 at end:" << endl;
    myList.AddNode(30);
    myList.PrintList();

    myList.ClearList();

    return 0;
}