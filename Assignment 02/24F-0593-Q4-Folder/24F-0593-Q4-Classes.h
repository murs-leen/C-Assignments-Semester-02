#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>
#include <iostream>
using namespace std;

enum QuestionType { MULTIPLE_CHOICE, TEXT_INPUT, RATING_SCALE };

class Question {
public:
    string questionText;
    QuestionType type;
    string* options;
    int optionCount;

    Question(string text, QuestionType t, int optCount = 0);
    void setOption(int index, string optionText);
    void display();
    ~Question();
};
class Survey {
public:
    string title;
    Question** questions;
    int questionCount;
    string** responses;
    int responseCount;

    Survey(string t);
    void edit();
    void createQuestions();
    void fillSurvey();
    void displayAnalytics();
    ~Survey();
};
class User {
public:
    string username;
    bool isAdmin;
    bool submitted;
    
    User(string uname, bool admin);
};
#endif
