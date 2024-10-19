#include <iostream>
using namespace std;

namespace Cats {
    class Cat {
    protected:
        string _name;
        string _type;
        int _age;
    public:
        Cat() {
            _name = "No name";
            _type = "Cat";
            _age = -1;
            cout << "Cat created" << endl;
        }
        Cat(string name, int age) {
            _name = name;
            _type = "Cat";
            _age = age;
            cout << "Cat created with param" << endl;
        }

        void about() {
            cout << "Name: " << _name << endl;
            cout << "Type: " << _type << endl;
            cout << "Age: " << _age << endl;
        }

        ~Cat() {
            cout << "Cat destroyed" << endl;
        }
    };
}

namespace Dogs {
    class Dog {
    protected:
        string _name;
        string _type;
        int _age;
    public:
        Dog() {
            _name = "No name";
            _type = "Dog";
            _age = -1;
            cout << "Dog created" << endl;
        }
        Dog(string name, int age) {
            _name = name;
            _type = "Dog";
            _age = age;
            cout << "Dog created with param" << endl;
        }

        void about() {
            cout << "Name: " << _name << endl;
            cout << "Type: " << _type << endl;
            cout << "Age: " << _age << endl;
        }

        ~Dog() {
            cout << "Dog destroyed" << endl;
        }
    };
}

namespace Parrots {
    class Parrot {
    protected:
        string _name;
        string _type;
        int _age;
    public:
        Parrot() {
            _name = "No name";
            _type = "Parrot";
            _age = -1;
            cout << "Parrot created" << endl;
        }
        Parrot(string name, int age) {
            _name = name;
            _type = "Parrot";
            _age = age;
            cout << "Parrot created with param" << endl;
        }

        void about() {
            cout << "Name: " << _name << endl;
            cout << "Type: " << _type << endl;
            cout << "Age: " << _age << endl;
        }

        ~Parrot() {
            cout << "Parrot destroyed" << endl;
        }
    };
}

int main() {
    Cats::Cat* cat = new Cats::Cat("Alex", 8);
    cat->about();
    delete cat;
    cout << endl;

    Dogs::Dog* dog = new Dogs::Dog("Buddy", 5);
    dog->about();
    delete dog;
    cout << endl;

    Parrots::Parrot* parrot = new Parrots::Parrot("Rio", 2);
    parrot->about();
    delete parrot;
    cout << endl;

    return 0;
}