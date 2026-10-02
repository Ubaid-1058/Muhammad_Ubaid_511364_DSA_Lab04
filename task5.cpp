// Muhammad Ubaid - 511364 - BSCS-15D
// Lab 04 - Task 5

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

    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == delData) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted." << endl;
            return;
        }

        node* curr = head;

        while (curr->next != nullptr && curr->next->data != delData) {
            curr = curr->next;
        }

        if (curr->next == nullptr) {
            cout << "Value not found." << endl;
        } else {
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Node deleted." << endl;
        }
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

    cout << "Deleting from empty list:" << endl;
    myList.DeleteNode(10);

    cout << endl << "Creating list 10, 20, 20, 30:" << endl;
    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(20);
    myList.AddNode(30);
    myList.PrintList();

    cout << endl << "Deleting 20 once:" << endl;
    myList.DeleteNode(20);
    myList.PrintList();

    cout << endl << "Deleting first node 10:" << endl;
    myList.DeleteNode(10);
    myList.PrintList();

    cout << endl << "Deleting last node 30:" << endl;
    myList.DeleteNode(30);
    myList.PrintList();

    cout << endl << "Deleting missing value 99:" << endl;
    myList.DeleteNode(99);
    myList.PrintList();

    cout << endl << "Deleting only remaining node 20:" << endl;
    myList.DeleteNode(20);
    myList.PrintList();

    myList.ClearList();

    return 0;
}