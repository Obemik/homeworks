#include <iostream>
#include <string> 
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        DeleteAll();
    }

    void AddToHead(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void AddToTail(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void DeleteFromHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteFromTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void DeleteAll() {
        while (head) {
            DeleteFromHead();
        }
    }

    void Show() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void InsertAtPosition(int pos, T value) {
        if (pos < 0) return;
        Node* newNode = new Node(value);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < pos - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) return;

        newNode->next = current->next;
        current->next = newNode;
    }

    void DeleteAtPosition(int pos) {
        if (pos < 0 || !head) return;
        if (pos == 0) {
            DeleteFromHead();
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < pos - 1; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) return;

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    int Search(T value) const {
        Node* current = head;
        int pos = 0;
        while (current) {
            if (current->data == value) {
                return pos;
            }
            current = current->next;
            pos++;
        }
        return -1;
    }

    int Replace(T oldValue, T newValue) {
        Node* current = head;
        int count = 0;
        while (current) {
            if (current->data == oldValue) {
                current->data = newValue;
                count++;
            }
            current = current->next;
        }
        return count > 0 ? count : -1;
    }

    void Reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList<int> list;

    list.AddToHead(10);
    list.AddToHead(20);
    list.AddToTail(30);
    list.AddToTail(40);

    cout << "List after adding elements to head and tail: ";
    list.Show();

    list.InsertAtPosition(2, 25);
    cout << "List after inserting 25 at position 2: ";
    list.Show();

    list.DeleteAtPosition(3);
    cout << "List after deleting element at position 3: ";
    list.Show();

    int pos = list.Search(30);
    cout << "Position of element 30: " << (pos != -1 ? to_string(pos) : "NULL") << endl;

    int replacedCount = list.Replace(25, 50);
    cout << "Number of elements replaced (25 -> 50): " << (replacedCount != -1 ? to_string(replacedCount) : "No replacements") << endl;

    list.Reverse();
    cout << "List after reversing: ";
    list.Show();

    list.DeleteAll();
    cout << "List after deleting all elements: ";
    list.Show();

    return 0;
}