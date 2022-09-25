/*
 Name: Leonardo Lapitan, 2001158908, CS135 1007, Lab6B
 Description: In this lab you will practice using basic file I/O, 1D arrays, parallel arrays.
Input: Enter a file name
**6b_data1.txt

Enter a name to search
**alex
Output:Names Forward: alex, john, jane, alex, alex, jane, john, ted
Scores Forward: 84, 97, 99, 91, 95, 100, 98, 55
Names Backward: ted, john, jane, alex, alex, jane, john, alex
Scores Backward: 55, 98, 100, 95, 91, 99, 97, 84
3 results for alex
Minimum: 84.00
Maximum: 95.00
Sum:     270.00
Average: 90.00
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
   ifstream iFile;
   string inFileName = "";

   cout << "Enter a file name" << endl
        << "**";
   cin >> inFileName;
   iFile.open(inFileName);

   while (!iFile.is_open())
   {
      cout << endl
           << "Error: Invalid file name." << endl;
      iFile.clear();
      iFile.ignore(1000, '\n');

      cout << "Enter a file name" << endl
           << "**";
      cin >> inFileName;
      iFile.open(inFileName);
   }

   string nameSearch = "";

   cout << endl
        << "Enter a name to search" << endl
        << "**";
   cin.ignore();
   cin.clear();
   getline(cin, nameSearch);

   string names[100];
   double scores[100];
   string line = "";
   int count = 0, nameCheck = 0;
   double Min = 1000.0, Max = 0.0, Sum = 0.0, Avg = 0.0;

   while (getline(iFile, line))
   {
      int spaceLocation = line.find(' ');
      names[count] = line.substr(0, spaceLocation);
      line = line.substr(spaceLocation + 1, line.length());
      scores[count] = stod(line);

      if (iFile.eof())
      {
         iFile.clear();
         iFile.ignore(1000, '\n');
      }

      if (names[count] == nameSearch)
      {
         if (scores[count] > Max)
         {
            Max = scores[count];
         }

         if (scores[count] < Min)
         {
            Min = scores[count];
         }

         Sum += scores[count];
         nameCheck++;
      }
      count++;
   }

   iFile.close();
   cout << endl
        << "Names Forward: ";
   for (int i = 0; i < count - 1; i++)
   {
      cout << names[i] << ", ";
   }
   cout << names[count - 1] << endl;

   cout << "Scores Forward: ";
   for (int i = 0; i < count - 1; i++)
   {
      cout << scores[i] << ", ";
   }
   cout << scores[count - 1] << endl;

   cout << "Names Reverse: ";
   for (int i = count - 1; i > 0; i--)
   {
      cout << names[i] << ", ";
   }
   cout << names[0] << endl;

   cout << "Scores Reverse: ";
   for (int i = count - 1; i > 0; i--)
   {
      cout << scores[i] << ", ";
   }
   cout << scores[0] << endl;

   if (nameCheck == 0)
   {
      cout << "Error: " << nameSearch << " is not a student in the list";
   }

   if (nameCheck != 0)
   {
      cout << nameCheck << " results for " << nameSearch << endl;
      cout << fixed << setprecision(2);
      cout << "Minimum: " << Min << endl;
      cout << "Maximum: " << Max << endl;
      cout << "Sum:     " << Sum << endl;

      Avg = Sum / nameCheck;
      cout << "Average: " << Avg << endl;
   }
   return 0;
}
