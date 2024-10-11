#include <iostream>
#include <vector>
using namespace std;

class Passport
{
protected:
    string _firstName;
    string _lastName;
    string _nationality;
    int _passportNumber;
    string _dateOfBirth;
public:
    Passport()
    {
        _firstName = "No name";
        _lastName = "No last name";
        _nationality = "Ukraine";
        _passportNumber = -1;
        _dateOfBirth = "00-00-0000";
        cout << "Passport created" << endl;
    }
    Passport(string firstName, string lastName, int passportNumber, string dateOfBirth)
    {
        _firstName = firstName;
        _lastName = lastName;
        _nationality = "Ukraine"; 
        _passportNumber = passportNumber;
        _dateOfBirth = dateOfBirth;
        cout << "Passport created with param" << endl;
    }

    virtual void about()
    {
        cout << "Name: " << _firstName << endl;
        cout << "Last name: " << _lastName << endl;
        cout << "Nationality: " << _nationality << endl;
        cout << "Passport number: " << _passportNumber << endl;
        cout << "Date of birth: " << _dateOfBirth << endl;
    }

    virtual ~Passport()
    {
        cout << "Passport destroyed" << endl;
    }
};

class ForeignPassport : public Passport
{
private:
    string foreignPassportNumber; 
    vector<string> visas;         
public:
    ForeignPassport() : Passport()
    {
        foreignPassportNumber = "No foreign passport number";
        cout << "ForeignPassport created" << endl;
    }

    ForeignPassport(string fName, string lName, int passportNumber, string dateOfBirth, string foreignPassportNumber)
        : Passport(fName, lName, passportNumber, dateOfBirth), foreignPassportNumber(foreignPassportNumber)
    {
        cout << "ForeignPassport created with param" << endl;
    }

    void addVisa(const string& visa)
    {
        visas.push_back(visa);
        cout << "Visa added: " << visa << endl;
    }

    void showVisas()
    {
        if (visas.empty())
        {
            cout << "No visas available." << endl;
        }
        else
        {
            cout << "Visas: " << endl;
            for (const string& visa : visas)
            {
                cout << "- " << visa << endl;
            }
        }
    }

    void about() override
    {
        Passport::about(); 
        cout << "Foreign Passport number: " << foreignPassportNumber << endl;
        showVisas();  
    }

    ~ForeignPassport()
    {
        cout << "ForeignPassport destroyed" << endl;
    }
};

int main()
{
    ForeignPassport fp("Ivan", "Ivanov", 123456, "01-01-1990", "FP987654");

    fp.addVisa("USA Visa");
    fp.addVisa("Schengen Visa");

    fp.about();

    return 0;
}