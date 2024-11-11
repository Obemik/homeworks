#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        else {
            front->prev = nullptr;
        }
        delete temp;
    }

    void printQueue() {
        Node<T>* temp = front;
        if (temp == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    Queue<T>* clone() {
        Queue<T>* newQueue = new Queue<T>();
        Node<T>* temp = front;
        while (temp != nullptr) {
            newQueue->enqueue(temp->data);
            temp = temp->next;
        }
        return newQueue;
    }

    Queue<T>* operator+(const Queue<T>& other) {
        Queue<T>* newQueue = this->clone();
        Node<T>* temp = other.front;
        while (temp != nullptr) {
            newQueue->enqueue(temp->data);
            temp = temp->next;
        }
        return newQueue;
    }

    Queue<T>* operator*(const Queue<T>& other) {
        Queue<T>* newQueue = new Queue<T>();
        Node<T>* temp1 = front;
        while (temp1 != nullptr) {
            Node<T>* temp2 = other.front;
            while (temp2 != nullptr) {
                if (temp1->data == temp2->data) {
                    newQueue->enqueue(temp1->data);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return newQueue;
    }
};

int main() {
    Queue<int> q1;
    Queue<int> q2;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    q2.enqueue(20);
    q2.enqueue(30);
    q2.enqueue(40);

    cout << "Queue 1 contents: ";
    q1.printQueue();

    cout << "Queue 2 contents: ";
    q2.printQueue();

    Queue<int>* clonedQueue = q1.clone();
    cout << "Cloned Queue contents: ";
    clonedQueue->printQueue();

    Queue<int>* unionQueue = q1 + q2;
    cout << "Union of Queue 1 and Queue 2: ";
    unionQueue->printQueue();

    Queue<int>* intersectionQueue = q1 * q2;
    cout << "Intersection of Queue 1 and Queue 2: ";
    intersectionQueue->printQueue();

    delete clonedQueue;
    delete unionQueue;
    delete intersectionQueue;

    return 0;
}