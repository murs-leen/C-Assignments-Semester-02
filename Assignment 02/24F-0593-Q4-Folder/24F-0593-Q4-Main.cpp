#include "24F-0593-Q4-Classes.h"
#include "24F-0593-Q4-Classes_Methods.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    Survey* survey = NULL;
    User* users[4];
    users[0] = new User("admin", true);
    users[1] = new User("user1", false);
    users[2] = new User("user2", false);
    users[3] = new User("user3", false);
    string uname;
    bool found;
    int choice = 0;
    while (choice != 3) {
        cout << "\n1. Login as Admin\n2. Login as User\n3. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            cout << "Enter Admin Username: ";
            getline(cin, uname);
            if (users[0]->username == uname) {
                int adminChoice;
                cout << "\nAdmin Menu:\n1. Create Survey\n2. View Analytics\n3. Edit Questions\nChoose: ";
                cin >> adminChoice;
                cin.ignore();
                if (adminChoice == 1) {
                    string title;
                    cout << "Enter survey title: ";
                    getline(cin, title);
                    delete survey;
                    survey = new Survey(title);
                    survey->createQuestions();
                }
                else if (adminChoice == 2) {
                    if (survey != NULL) {
                        survey->displayAnalytics();
                    }
                    else {
                        cout << "No survey available.\n";
                    }
                }
                else if (adminChoice == 3) {
                    if (survey != NULL) {
                        survey->edit();
                    }
                    else {
                        cout << "No survey available to edit.\n";
                    }
                }
            }
            else {
                cout << "Invalid Admin Username.\n";
            }
            break;
        case 2:
            cout << "Enter User Username: ";
            getline(cin, uname);
            found = false;
            for (int i = 1; i <= 3 && found == false; i++) {
                if (users[i]->username == uname) {
                    found = true;
                    if (!users[i]->submitted) {
                        if (survey != NULL) {
                            survey->fillSurvey();
                            users[i]->submitted = true;
                        }
                        else {
                            cout << "No survey created by admin yet.\n";
                        }
                    }
                    else {
                        cout << "You have already submitted the survey.\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Invalid User Username.\n";
            }
            break;
        case 3:
            cout << "Exiting!!!";
            break;
        default:
            cout << "Invalid Choice!";
            break;
        }
    }
    delete survey;
    for (int i = 0; i < 4; i++) delete users[i];
    return 0;
}