#include <iostream>
#include "24F-0593-Q4-Classes.h"
using namespace std;

Question::Question(string text, QuestionType t, int optCount) {
    questionText = text;
    type = t;
    optionCount = optCount;
    if (optCount > 0) {
        options = new string[optCount];
    }
    else {
        options = NULL;
    }
}
void Question::setOption(int index, string optionText) {
    if (index >= 0 && index < optionCount) {
        options[index] = optionText;
    }
}
void Question::display() {
    cout << questionText << endl;
    for (int i = 0; i < optionCount; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}
Question::~Question() {
    delete[] options;
}

// ------------------------------------------------------------

Survey::Survey(string t) {
    title = t;
    questionCount = 0;
    responseCount = 0;
    questions = NULL;
    responses = NULL;
}
void Survey::edit() {
    if (questionCount == 0) {
        cout << "No questions to edit.\n";
        return;
    }
    for (int i = 0; i < questionCount; i++) {
        cout << i + 1 << ". " << questions[i]->questionText << endl;
    }
    int qNum;
    cout << "Enter the question number you want to edit: ";
    cin >> qNum;
    cin.ignore();
    if (qNum < 1 || qNum > questionCount) {
        cout << "Invalid question number.\n";
        return;
    }
    string newText;
    cout << "Enter the new question text: ";
    getline(cin, newText);
    questions[qNum - 1]->questionText = newText;
    if (questions[qNum - 1]->type == MULTIPLE_CHOICE || questions[qNum - 1]->type == RATING_SCALE) {
        cout << "Do you want to edit options? (1-Yes, 0-No): ";
        int editOpt;
        cin >> editOpt;
        cin.ignore();
        if (editOpt == 1) {
            cout << "Enter the number of options: ";
            int newOptCount;
            cin >> newOptCount;
            cin.ignore();
            delete[] questions[qNum - 1]->options;
            questions[qNum - 1]->optionCount = newOptCount;
            questions[qNum - 1]->options = new string[newOptCount];
            for (int i = 0; i < newOptCount; i++) {
                cout << "Enter option " << i + 1 << ": ";
                string opt;
                getline(cin, opt);
                questions[qNum - 1]->options[i] = opt;
            }
        }
    }
    cout << "Question updated successfully.\n";
}
void Survey::createQuestions() {
    cout << "How many questions? ";
    cin >> questionCount;
    cin.ignore();
    questions = new Question * [questionCount];
    for (int i = 0; i < questionCount; i++) {
        string qText;
        int qType, optCount = 0;
        cout << "Enter question text: ";
        getline(cin, qText);
        cout << "Question Type (0-MC, 1-Text, 2-Rating): ";
        cin >> qType;
        cin.ignore();
        if (qType == 0 || qType == 2) {
            cout << "Number of options: ";
            cin >> optCount;
            cin.ignore();
        }
        questions[i] = new Question(qText, (QuestionType)qType, optCount);
        for (int j = 0; j < optCount; j++) {
            string opt;
            cout << "Option " << j + 1 << ": ";
            getline(cin, opt);
            questions[i]->setOption(j, opt);
        }
    }
}
void Survey::fillSurvey() {
    string* userResponses = new string[questionCount];
    for (int i = 0; i < questionCount; i++) {
        questions[i]->display();
        string ans;
        cout << "Your answer: ";
        getline(cin, ans);
        userResponses[i] = new char[ans.size() + 1];
        userResponses[i] = ans;
    }
    string** newResponses = new string * [responseCount + 1];
    for (int i = 0; i < responseCount; i++) {
        newResponses[i] = responses[i];
    }
    newResponses[responseCount] = userResponses;
    delete[] responses;
    responses = newResponses;
    responseCount++;
}
void Survey::displayAnalytics() {
    cout << "Survey: " << title << " | Total Responses: " << responseCount << endl;
    for (int i = 0; i < questionCount; i++) {
        cout << "\nQ" << i + 1 << ": " << questions[i]->questionText << endl;
        if (questions[i]->type == MULTIPLE_CHOICE || questions[i]->type == RATING_SCALE) {
            int* counts = new int[questions[i]->optionCount];
            for (int k = 0; k < questions[i]->optionCount; k++) counts[k] = 0;
            for (int j = 0; j < responseCount; j++) {
                int selected = responses[j][i][0] - '0' - 1;
                if (selected >= 0 && selected < questions[i]->optionCount) {
                    counts[selected]++;
                }
            }
            for (int k = 0; k < questions[i]->optionCount; k++) {
                cout << questions[i]->options[k] << ": " << counts[k] << " responses" << endl;
            }
            delete[] counts;
        }
        else {
            for (int j = 0; j < responseCount; j++) {
                cout << "- " << responses[j][i] << endl;
            }
        }
    }
}
Survey::~Survey() {
    for (int i = 0; i < questionCount; i++) {
        delete questions[i];
    }
    delete[] questions;
    for (int i = 0; i < responseCount; i++) {
        delete[] responses[i];
    }
    delete[] responses;
}

User::User(string uname, bool admin) {
    username = uname;
    isAdmin = admin;
    submitted = false;
}