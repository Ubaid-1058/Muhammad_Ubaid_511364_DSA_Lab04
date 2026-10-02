// Muhammad Ubaid - 511364 - BSCS-15D
// Lab 04 - Task 3

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

    void SearchNode(int searchData) {
        node* curr = head;
        int position = 1;

        while (curr != nullptr) {
            if (curr->data == searchData) {
                cout << "Value found at position " << position << endl;
                return;
            }
            curr = curr->next;
            position++;
        }

        cout << "Value not found" << endl;
    }

    void PrintSecondNode() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Second node does not exist." << endl;
        } else {
            cout << "Second node: " << head->next->data << endl;
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

    cout << "Testing empty list:" << endl;
    myList.PrintList();
    myList.PrintSecondNode();
    myList.SearchNode(20);

    cout << endl << "Testing one-node list:" << endl;
    myList.AddNode(10);
    myList.PrintList();
    myList.PrintSecondNode();

    myList.ClearList();

    cout << endl << "Testing list 10, 20, 30, 20:" << endl;
    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(30);
    myList.AddNode(20);

    myList.PrintList();
    myList.PrintSecondNode();

    myList.SearchNode(20);
    myList.SearchNode(99);

    myList.ClearList();

    return 0;
}