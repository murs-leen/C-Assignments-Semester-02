#include <iostream>
#include <string>
#include <exception>
using namespace std;

class ageException : public exception {
public:
    const char* what() {
        return "You are older than the requested age : (25 years).";
    }
};

class gpaException : public exception {
public:
    const char* what() {
        return "Your GPA is not sufficient to apply for this job : (2.5)";
    }
};

int main() {
    int age;
    float gpa;
    cout << "Enter your age: ";
    cin >> age;

    try {
        if (age > 25) {
            throw ageException();
        }
        cout << "Enter your GPA: ";
        cin >> gpa;

        try {
            if (gpa < 2.5) {
                throw gpaException();
            }
            cout << "Application is accepted." << endl;
        }
        catch (gpaException& e) {
            cout << " Error: " << e.what() << endl;
        }
    }
    catch (ageException& e) {
        cout << " Error: " << e.what() << endl;
    }
    return 0;
}
