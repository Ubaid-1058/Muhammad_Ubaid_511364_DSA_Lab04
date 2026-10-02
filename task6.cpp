// Muhammad Ubaid - 511364 - BSCS-15D
// Lab 04 - Task 6

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

    int CountNodes() {
        int count = 0;
        node* curr = head;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }

        return count;
    }

    void PrintSecondNode() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Second node does not exist." << endl;
        } else {
            cout << "Second node: " << head->next->data << endl;
        }
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

void DisplayMenu() {
    cout << endl;
    cout << "====== MENU ======" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Search by value" << endl;
    cout << "4. Delete by value" << endl;
    cout << "5. Display all nodes" << endl;
    cout << "6. Count nodes" << endl;
    cout << "7. Display second node" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    List myList;
    int choice, value;

    do {
        DisplayMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            myList.InsertAtBeginning(value);
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            myList.AddNode(value);
        } else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value;
            myList.SearchNode(value);
        } else if (choice == 4) {
            cout << "Enter value to delete: ";
            cin >> value;
            myList.DeleteNode(value);
        } else if (choice == 5) {
            myList.PrintList();
        } else if (choice == 6) {
            cout << "Total nodes: " << myList.CountNodes() << endl;
        } else if (choice == 7) {
            myList.PrintSecondNode();
        } else if (choice == 8) {
            myList.ClearList();
            cout << "Program ended." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);

    return 0;
}