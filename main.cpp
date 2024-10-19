#include <iostream>
using namespace std;

namespace AnimalsBase {
    class Animal {
    protected:
        string _name;
        string _type;
        int _age;
    public:
        Animal() {
            _name = "No name";
            _type = "No type";
            _age = -1;
            cout << "Animal created" << endl;
        }
        Animal(string name, string type, int age) {
            _name = name;
            _type = type;
            _age = age;
            cout << "Animal created with param" << endl;
        }

        virtual void about() {
            cout << "Name: " << _name << endl;
            cout << "Type: " << _type << endl;
            cout << "Age: " << _age << endl;
        }

        virtual ~Animal() {
            cout << "Animal destroyed" << endl;
        }
    };
}

namespace Cats {
    class Cat : public AnimalsBase::Animal {
    public:
        Cat() : Animal() {
            _type = "Cat";
            cout << "Cat created" << endl;
        }
        Cat(string name, int age) : Animal(name, "Cat", age) {
            cout << "Cat created with param" << endl;
        }

        void about() override {
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
    class Dog : public AnimalsBase::Animal {
    public:
        Dog() : Animal() {
            _type = "Dog";
            cout << "Dog created" << endl;
        }
        Dog(string name, int age) : Animal(name, "Dog", age) {
            cout << "Dog created with param" << endl;
        }

        void about() override {
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
    class Parrot : public AnimalsBase::Animal {
    public:
        Parrot() : Animal() {
            _type = "Parrot";
            cout << "Parrot created" << endl;
        }
        Parrot(string name, int age) : Animal(name, "Parrot", age) {
            cout << "Parrot created with param" << endl;
        }

        void about() override {
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