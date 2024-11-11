#include <iostream>
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
};

int main() {
    LinkedList<int> list;

    list.AddToHead(10);
    list.AddToHead(20);
    list.AddToTail(30);
    list.AddToTail(40);

    cout << "List after adding elements to head and tail: ";
    list.Show();

    list.DeleteFromHead();
    cout << "List after deleting from head: ";
    list.Show();

    list.DeleteFromTail();
    cout << "List after deleting from tail: ";
    list.Show();

    list.DeleteAll();
    cout << "List after deleting all elements: ";
    list.Show();

    return 0;
}