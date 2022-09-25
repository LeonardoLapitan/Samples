/*
 Name: Leonardo Lapitan, 2001158908, CS135 1007, Lab10A
 Description: In this lab you will practice using 
 basic input/output, creating a C++ struct, passing a 
 struct to a function, saving data to and
reading from a struct.
Input: Enter a first name
**John

Enter a last name
**Smith

Enter a grade
**4
Output:Data Entered
  student.firstName    = John
  student.lastName     = Smith
  student.grade        = 4
  student.letterGrade  = A
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Declaring Struct

struct studentType
{
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};

//Function Prototypes

void getStudentData(studentType &);
void getLetterGrade(studentType &);
void printStudentData(studentType);

//Main Function

int main(int argc, char const *argv[])
{
    studentType student;

    getStudentData(student);
    cin.clear();
    getLetterGrade(student);
    printStudentData(student);

    return 0;
}

//Function to Prompt and Store Student's First and Last Names

void getStudentData(studentType &student)
{
    cout << "Enter a first name" << endl
         << "**";
    getline(cin, student.firstName);

    cout << endl
         << "Enter a last name" << endl
         << "**";
    getline(cin, student.lastName);
}

//Function to Prompt and Store Student's Grade
//Loop on an invalid input

void getLetterGrade(studentType &student)
{
    bool flag = false;
    cout << endl;

    do
    {
        cout << "Enter a grade" << endl
             << "**";
        cin >> student.grade;

        flag = cin.fail();
        if (flag || student.grade < 0 || student.grade > 4)
        {
            cout << endl
                 << "Error: Invalid grade" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (flag || student.grade < 0 || student.grade > 4);
}

//Function to Print Out Student's Data

void printStudentData(studentType student)
{
    cout << endl << "Data Entered" << left << endl;
    cout << "  " << setw(20) << "student.firstName"
         << "= " << student.firstName << endl;
    cout << "  " << setw(20) << "student.lastName"
         << "= " << student.lastName << endl;
    cout << "  " << setw(20) << "student.grade"
         << "= " << student.grade << endl;
    if (student.grade == 0)
    {
        cout << "  " << setw(20) << "student.letterGrade"
             << "= F" << endl;
    }
    else if (student.grade == 1)
    {
        cout << "  " << setw(20) << "student.letterGrade"
             << "= D" << endl;
    }
    else if (student.grade == 2)
    {
        cout << "  " << setw(20) << "student.letterGrade"
             << "= C" << endl;
    }
    else if (student.grade == 3)
    {
        cout << "  " << setw(20) << "student.letterGrade"
             << "= B" << endl;
    }
    else if (student.grade == 4)
    {
        cout << "  " << setw(20) << "student.letterGrade"
             << "= A" << endl;
    }
}
