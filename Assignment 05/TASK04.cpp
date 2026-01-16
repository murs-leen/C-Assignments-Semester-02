//#include<iostream>
//using namespace std;
//
//int main() {
//    int n;
//    float sum = 0, avg = 0;
//    while (true) {
//        cout << "Enter the value of N (non-negative): ";
//        cin >> n;
//        if (cin.fail()) {
//            cout << "Invalid input. Please enter an integer." << endl;
//            cin.clear();
//            cin.ignore();
//            continue;
//        }
//        try {
//            if (n < 0)
//                throw "-ve number entered.";
//            break; // valid input
//        }
//        catch (const char* msg) {
//            cout << msg << endl;
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        int num;
//        while (true) {
//            cout << "Enter number " << i + 1 << ": ";
//            cin >> num;
//            if (cin.fail()) {
//                cout << "Invalid input. Please enter an integer." << endl;
//                cin.clear();
//                cin.ignore();
//            }
//            else {
//                sum += num;
//                break;
//            }
//        }
//    }
//    if (n > 0) {
//        avg = sum / n;
//        cout << "Average = " << avg << endl;
//    }
//    else {
//        cout << "No numbers entered to compute average." << endl;
//    }
//    return 0;
//}
