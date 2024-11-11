#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class Array {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    int capacity;

    void Add(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        size++;
    }

public:
    Array() : head(nullptr), tail(nullptr), size(0), capacity(0) {}

    ~Array() {
        RemoveAll();
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int grow = 1) {
        if (newSize > capacity) {
            capacity = newSize;
            while (size < newSize) {
                Add(T());
            }
        }
        else if (newSize < size) {
            Node<T>* temp = head;
            for (int i = 0; i < newSize; ++i) {
                temp = temp->next;
            }
            while (temp != nullptr) {
                Node<T>* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            tail = temp;
        }
        size = newSize;
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        int newCapacity = size;
        if (newCapacity < capacity) {
            capacity = newCapacity;
        }
    }

    void RemoveAll() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        head = tail = nullptr;
        size = 0;
        capacity = 0;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->data = value;
    }

    T& operator[](int index) {
        return GetAt(index);
    }

    void AddElement(const T& value) {
        Add(value);
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of bounds");
        }
        Node<T>* newNode = new Node<T>(value);
        if (index == 0) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
        if (newNode->next == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev;
        }
        delete temp;
        size--;
    }

    Array<T> Append(const Array<T>& other) {
        Array<T> result;
        Node<T>* temp = head;
        while (temp != nullptr) {
            result.Add(temp->data);
            temp = temp->next;
        }
        temp = other.head;
        while (temp != nullptr) {
            result.Add(temp->data);
            temp = temp->next;
        }
        return result;
    }

    void Print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Array<int> arr;
    arr.AddElement(1);
    arr.AddElement(2);
    arr.AddElement(3);
    arr.AddElement(4);
    arr.AddElement(5);

    cout << "Array elements: ";
    arr.Print();

    arr.InsertAt(2, 99);
    cout << "Array after InsertAt(2, 99): ";
    arr.Print();

    arr.RemoveAt(4);
    cout << "Array after RemoveAt(4): ";
    arr.Print();

    Array<int> arr2;
    arr2.AddElement(10);
    arr2.AddElement(20);

    Array<int> mergedArr = arr.Append(arr2);
    cout << "Array after Append(arr2): ";
    mergedArr.Print();

    return 0;
}