#include <iostream>
using namespace std;

class Animal
{
protected:
    string _name;
    string _type;
    int _age;
public:
    Animal()
    {
        _name = "No name";
        _type = "No type";
        _age = -1;
        cout << "Animal created" << endl;
    }
    Animal(string name, string type, int age)
    {
        _name = name;
        _type = type;
        _age = age;
        cout << "Animal created with param" << endl;
    }

    virtual void about()
    {
        cout << "Name: " << _name << endl;
        cout << "Type: " << _type << endl;
        cout << "Age: " << _age << endl;
    }

    virtual ~Animal()
    {
        cout << "Animal destroyed" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal()
    {
        cout << "Cat created" << endl;
    }
    Cat(string name, int age) : Animal(name, "Cat", age)
    {
        cout << "Cat created with param" << endl;
    }

    void about() override
    {
        cout << "Name: " << _name << endl;
        cout << "Type: " << _type << endl;
        cout << "Age: " << _age << endl;
    }

    ~Cat()
    {
        cout << "Cat destroyed" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog() : Animal()
    {
        cout << "Dog created" << endl;
    }
    Dog(string name, int age) : Animal(name, "Dog", age)
    {
        cout << "Dog created with param" << endl;
    }

    void about() override
    {
        cout << "Name: " << _name << endl;
        cout << "Type: " << _type << endl;
        cout << "Age: " << _age << endl;
    }

    ~Dog()
    {
        cout << "Dog destroyed" << endl;
    }
};

class Parrot : public Animal
{
public:
    Parrot() : Animal()
    {
        cout << "Parrot created" << endl;
    }
    Parrot(string name, int age) : Animal(name, "Parrot", age)
    {
        cout << "Parrot created with param" << endl;
    }

    void about() override
    {
        cout << "Name: " << _name << endl;
        cout << "Type: " << _type << endl;
        cout << "Age: " << _age << endl;
    }

    ~Parrot()
    {
        cout << "Parrot destroyed" << endl;
    }
};

void print(Animal* animal)
{
    animal->about();
}

int main() {
    Cat* cat = new Cat("Alex", 8);
    print(cat);
    delete cat;
    cout << endl;

    Dog* dog = new Dog("Buddy", 5);
    print(dog);
    delete dog;
    cout << endl;

    Parrot* parrot = new Parrot("Rio", 2);
    print(parrot);
    delete parrot;
    cout << endl;

    return 0;
}