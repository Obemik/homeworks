#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    LinkedList clone() const {
        LinkedList clonedList;
        if (!head) return clonedList;

        Node* currentOriginal = head;
        LinkedList tempList;
        while (currentOriginal) {
            tempList.push(currentOriginal->data);
            currentOriginal = currentOriginal->next;
        }

        Node* currentTemp = tempList.head;
        while (currentTemp) {
            clonedList.push(currentTemp->data);
            currentTemp = currentTemp->next;
        }

        return clonedList;
    }

    LinkedList operator+(const LinkedList& other) const {
        LinkedList result;

        Node* current = this->head;
        while (current) {
            result.push(current->data);
            current = current->next;
        }

        current = other.head;
        while (current) {
            result.push(current->data);
            current = current->next;
        }

        result.reverse();
        return result;
    }

    LinkedList operator*(const LinkedList& other) const {
        LinkedList result;

        Node* currentA = this->head;
        while (currentA) {
            Node* currentB = other.head;
            while (currentB) {
                if (currentA->data == currentB->data) {
                    result.push(currentA->data);
                    break;
                }
                currentB = currentB->next;
            }
            currentA = currentA->next;
        }

        result.reverse();
        return result;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void reverse() {
        if (!head) return;
        Node* prev = nullptr;
        Node* current = head;

        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
};

int main() {
    LinkedList list1, list2;

    list1.push(1);
    list1.push(2);
    list1.push(3);

    list2.push(3);
    list2.push(2);
    list2.push(5);
    list2.push(6);

    LinkedList cloneList = list1.clone();
    cout << "Cloned list: ";
    cloneList.print();

    LinkedList sumList = list1 + list2;
    LinkedList intersectionList = list1 * list2;

    cout << "Sum of lists: ";
    sumList.print();

    cout << "Intersection of lists: ";
    intersectionList.print();

    return 0;
}