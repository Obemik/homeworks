#include "menu.h"
#include <iostream>

void Menu::displayMainMenu() {
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. Add Patient" << std::endl;
    std::cout << "2. Add Doctor" << std::endl;
    std::cout << "3. Display All Patients" << std::endl;
    std::cout << "4. Display All Doctors" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void Menu::handleInput() {
    int choice;
    while (true) {
        try {
            displayMainMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a number.");
            }

            switch (choice) {
            case 1: {
                std::string name, patientID, address;
                int age;
                Gender gender;

                std::cout << "Enter name: ";
                std::cin >> name;

                while (true) {
                    std::cout << "Enter age: ";
                    std::cin >> age;
                    if (std::cin.fail()) {
                        std::cin.clear(); 
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                        std::cout << "Invalid input. Please enter a valid number for age.\n";
                    }
                    else {
                        break; 
                    }
                }

                while (true) {
                    int g;
                    std::cout << "Enter gender (0 for Male, 1 for Female): ";
                    std::cin >> g;
                    if (std::cin.fail() || (g != 0 && g != 1)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter 0 for Male or 1 for Female.\n";
                    }
                    else {
                        gender = (g == 0) ? Male : Female;
                        break;
                    }
                }

                std::cout << "Enter patient ID: ";
                std::cin >> patientID;

                std::cout << "Enter address: ";
                std::cin >> address;

                Patient newPatient(name, age, gender, patientID, address);
                database.addPatient(newPatient);
                break;
            }
            case 2: {
                std::string name, specialization, doctorID;

                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter specialization: ";
                std::cin >> specialization;
                std::cout << "Enter doctor ID: ";
                std::cin >> doctorID;

                Doctor newDoctor(name.c_str(), specialization.c_str(), doctorID.c_str());
                database.addDoctor(newDoctor);
                break;
            }
            case 3:
                database.displayAllPatients();
                break;
            case 4:
                database.displayAllDoctors();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}
