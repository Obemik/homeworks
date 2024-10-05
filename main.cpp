#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
private:
    T* _data = nullptr;
public:
    Node() = default;
    Node(T data)
    {
        _data = new T{ data };
    }
    Node(const Node& other)
    {
        _data = new T{ *other._data };
    }
    T* get_data()
    {
        return _data;
    }
    ~Node()
    {
        if (_data != nullptr)
            delete _data;
    }
};

template<typename T>
class Stack
{
private:
    Node<T>** _items = nullptr;
    const int _step = 10;
    int _size;
    int _fact_size = 0;

    void check_resize()
    {
        if (_fact_size == _size - 1)
        {
            resize();
        }
    }

    void resize()
    {
        Node<T>** new_items = new Node<T>*[_size + _step];
        for (int i = 0; i < _size; i++)
        {
            new_items[i] = _items[i];
        }
        delete[] _items;
        _items = new_items;
        _size += _step;
    }
public:
    Stack()
    {
        _size = _step;
        _items = new Node<T>*[_size];
    }

    void push(T value)
    {
        check_resize();
        Node<T>* new_node = new Node<T>(value);
        _items[_fact_size] = new_node;
        _fact_size++;
    }

    T pop()
    {
        if (_fact_size == 0)
        {
            throw std::out_of_range("Stack is empty");
        }
        Node<T>* item = _items[_fact_size - 1];
        T* data = item->get_data();
        T result = *data;
        delete item;
        _fact_size--;
        return result;
    }

    T top()
    {
        if (_fact_size == 0)
        {
            throw std::out_of_range("Stack is empty");
        }
        Node<T>* item = _items[_fact_size - 1];
        T* data = item->get_data();
        T result = *data;
        return result;
    }

    bool is_empty() const
    {
        return _fact_size == 0;
    }

    ~Stack()
    {
        delete[] _items;
    }
};

bool is_matching_pair(char open, char close)
{
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void check_brackets(const string& str)
{
    Stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        char current = str[i];

        if (current == '(' || current == '{' || current == '[')
        {
            stack.push(current);
        }
        else if (current == ')' || current == '}' || current == ']')
        {
            if (stack.is_empty())
            {
                cout << "Error: no matching opening bracket for " << current << " at position " << i << endl;
                return;
            }
            char top = stack.pop();
            if (!is_matching_pair(top, current))
            {
                cout << "Error: opening bracket " << top << " doesn't match closing bracket " << current << " at position " << i << endl;
                return;
            }
        }
    }

    if (!stack.is_empty())
    {
        cout << "Error: not all opening brackets are matched" << endl;
    }
    else
    {
        cout << "The string is correct" << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string to check: ";
    getline(cin, input);

    check_brackets(input);

    return 0;
}