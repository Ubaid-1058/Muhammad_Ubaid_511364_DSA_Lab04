// Muhammad Ubaid - 511364 - BSCS-15D
// Lab 04 - Task 2

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

    int CountNodes() {
        int count = 0;
        node* curr = head;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        return count;
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
    int n, value;

    cout << "How many nodes do you want to add? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter value " << i << ": ";
        cin >> value;

        myList.AddNode(value);
    }

    cout << endl << "Linked List: ";
    myList.PrintList();

    cout << "Total nodes: " << myList.CountNodes() << endl;

    myList.ClearList();

    return 0;
}