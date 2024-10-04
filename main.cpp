#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class String {
protected:
    char* _data;
    int _length;

public:
    String() {
        _data = nullptr;
        _length = 0;
    }

    String(const char* str) {
        _length = strlen(str);
        _data = new char[_length + 1];
        strcpy(_data, str);
    }

    String(const String& other) {
        _length = other._length;
        _data = new char[_length + 1];
        strcpy(_data, other._data);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;

        delete[] _data;
        _length = other._length;
        _data = new char[_length + 1];
        strcpy(_data, other._data);

        return *this;
    }

    int length() const {
        return _length;
    }

    void clear() {
        delete[] _data;
        _data = nullptr;
        _length = 0;
    }

    String operator+(const String& other) const {
        String result;
        result._length = _length + other._length;
        result._data = new char[result._length + 1];
        strcpy(result._data, _data);
        strcat(result._data, other._data);

        return result;
    }

    String& operator+=(const String& other) {
        _length += other._length;
        char* newData = new char[_length + 1];
        strcpy(newData, _data);
        strcat(newData, other._data);
        delete[] _data;
        _data = newData;

        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(_data, other._data) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    virtual ~String() {
        delete[] _data;
    }

    void print() const {
        if (_data)
            cout << _data << endl;
        else
            cout << "Empty string" << endl;
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* str) : String() {
        bool isValid = true;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] != '0' && str[i] != '1') {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            _length = strlen(str);
            _data = new char[_length + 1];
            strcpy(_data, str);
        }
        else {
            _data = nullptr;
            _length = 0;
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    void negate() {
        for (int i = 0; i < _length; i++) {
            _data[i] = (_data[i] == '0') ? '1' : '0';
        }
        bool carry = true;
        for (int i = _length - 1; i >= 0 && carry; i--) {
            if (_data[i] == '0') {
                _data[i] = '1';
                carry = false;
            }
            else {
                _data[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        int maxLength = max(_length, other._length);
        BitString result;
        result._data = new char[maxLength + 1];
        result._length = maxLength;

        int carry = 0;
        for (int i = maxLength - 1; i >= 0; i--) {
            int bit1 = (i < _length) ? _data[i] - '0' : 0;
            int bit2 = (i < other._length) ? other._data[i] - '0' : 0;
            int sum = bit1 + bit2 + carry;
            result._data[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
        result._data[maxLength] = '\0';

        return result;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }

    ~BitString() {}
};

int main() {
    String str1("Hello");
    String str2(" World");
    str1 += str2;
    str1.print();

    BitString bitStr1("1010");
    BitString bitStr2("0101");
    BitString bitSum = bitStr1 + bitStr2;
    bitSum.print();

    bitStr1.negate();
    bitStr1.print();

    return 0;
}