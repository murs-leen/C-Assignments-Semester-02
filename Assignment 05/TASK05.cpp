//#include <iostream>
//#include <string>
//using namespace std;
//class invalidHour {
//public:
//    const char* Error() {
//        return "Inavalid hour value!";
//    }
//};
//class invalidMin {
//public:
//    const char* Error() {
//        return "Invalid minute value!";
//    }
//};
//class invalidSec {
//public:
//    const char* Error() {
//        return "Invalid second value!";
//    }
//};
//int main() {
//    int hour, min, sec;
//    string timePeriod;
//    try {
//        cout << "Enter hour: ";
//        cin >> hour;
//        if (hour < 1 || hour > 12)
//            throw invalidHour();
//        cout << "Enter minute: ";
//        cin >> min;
//        if (min < 0 || min > 59)
//            throw invalidMin();
//        cout << "Enter second: ";
//        cin >> sec;
//        if (sec < 0 || sec > 59)
//            throw invalidSec();
//        cout << "Enter AM/PM: ";
//        cin >> timePeriod;
//        if (timePeriod == "PM" || timePeriod == "pm") {
//            if (hour != 12)
//                hour += 12;
//        }
//        else if (timePeriod == "AM" || timePeriod == "am") {
//            if (hour == 12)
//                hour = 0;
//        }
//        else {
//            cout << "Invalid period input." << endl;
//            return 0;
//        }
//        cout << "Time in 24-Hr format: " << hour << ':' << min << ':' << sec << endl;
//    }
//    catch (invalidHour& val) {
//        cout << "Error: " << val.Error() << endl;
//    }
//    catch (invalidMin& val) {
//        cout << "Error: " << val.Error() << endl;
//    }
//    catch (invalidSec& val) {
//        cout << "Error: " << val.Error() << endl;
//    }
//    return 0;
//}
