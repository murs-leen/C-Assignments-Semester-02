//#include <iostream>
//#include <cstring>  
//#include <conio.h>
//using namespace std;
//
//void GenerateCode(int* P1, int* P2, char* line);
//void Decode(int* P1, int* P2, char* line);
//
//int main()
//{
//   string rollNo;
//   char line[50];
//   char ch;
//   cout << "Enter your roll no: ";
//   bool flag = false;
//
//   while (!flag)
//{
//       rollNo.clear();
//       while ((ch = _getch()) != '\r')
//{
//           cout << ch;
//           rollNo += ch;
//           if (ch == 'f' || ch == 'F' ||
//               ch == 'i' || ch == 'I' ||
//               ch == 'p' || ch == 'P' ||
//               ch == 'l' || ch == 'L' ||
//               ch == 'k' || ch == 'K') {
//               cout << '-';
//               rollNo += '-';
//           }
//       }
//       flag = true;
//       int leng = rollNo.length();
//       if (leng == 8)
//           break;
//       else {
//           cout << "\nInvalid rollno..." << endl;
//           cout << "Please enter correct rollNo: ";
//           flag = false;
//       }
//   }
//   cout << endl;
//
//   int a = (rollNo[4] - '0') + (rollNo[5] - '0') + 1; // For capital letters
//   int b = (rollNo[6] - '0') + (rollNo[7] - '0') + 1; // For small letters
//   int* P1 = &a;
//   int* P2 = &b;
//
//   cout << "Enter original line: ";
//   cin.getline(line, 50);
//
//   // Encode the line
//   GenerateCode(P1, P2, line);
//   cout << "Encoded line: " << line << endl;
//
//   // Decode the line
//   Decode(P1, P2, line);
//   cout << "Decoded line: " << line << endl;
//   return 0;
//}
//
//void GenerateCode(int* P1, int* P2, char* line)
//{
//   for (int i = 0; i < strlen(line); ++i) 
//{
//       if (line[i] >= 'A' && line[i] <= 'Z') 
//       {
//           int encoded = line[i] + *P1;
//           if (encoded > 'Z')
//               encoded = 'A' + (encoded - 'Z' - 1);
//           line[i] = encoded;
//       }
//       else if (line[i] >= 'a' && line[i] <= 'z') 
//       {
//           int encoded = line[i] + *P2;
//           if (encoded > 'z')
//               encoded = 'a' + (encoded - 'z' - 1);
//           line[i] = encoded;
//       }
//   }
//}
//
//void Decode(int* P1, int* P2, char* line) 
//{
//   for (int i = 0; i < strlen(line); ++i) 
//   {
//       if (line[i] >= 'A' && line[i] <= 'Z') 
//       {
//           int decoded = line[i] - *P1;
//           if (decoded < 'A')
//               decoded = 'Z' - ('A' - decoded - 1);
//           line[i] = decoded;
//       }
//       else if (line[i] >= 'a' && line[i] <= 'z') 
//       {
//           int decoded = line[i] - *P2;
//           if (decoded < 'a')
//               decoded = 'z' - ('a' - decoded - 1);
//           line[i] = decoded;
//       }
//   }
//}
