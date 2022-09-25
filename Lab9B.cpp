/*
 Name: Leonardo Lapitan, 2001158908, CS135 1007, Lab9B
 Description: In this lab you will practice using basic 
 input/output, user defined functions, and function 
 overloading.
Input:Enter an integer between 1 and 50
**6

Enter another integer between 1 and 50
**6

Enter a string
**hi

Enter another string
**hello
Output:6 + 6 = 12
hi + hello = hihello
6 * 6 = 36
hi * 6 = hihihihihihi
hello * 6 = hellohellohellohellohellohello
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int add(int, int);
string add(string, string);
int multiply(int, int);
string multiply(string, int);

int getIntInput(string, int, int);
string getStringInput(string);
bool checkFailure(int, int, int);

int main()
{
    int MIN = 1, MAX = 50;

    //Prompts for the User

    string prompt1Int = "Enter an integer between " +
                        to_string(MIN) + " and " +
                        to_string(MAX) + "\n**";
    string prompt2Int = "Enter another integer between " +
                        to_string(MIN) + " and " +
                        to_string(MAX) + "\n**";
    string prompt1String = "Enter a string \n**";
    string prompt2String = "Enter another string \n**";

    //Getting Integers and Strings from the User

    int int1 = getIntInput(prompt1Int, MIN, MAX);
    int int2 = getIntInput(prompt2Int, MIN, MAX);
    cin.ignore();
    string string1 = getStringInput(prompt1String);
    string string2 = getStringInput(prompt2String);

    //Calculations

    int intSum = add(int1, int2);
    string stringSum = add(string1, string2);
    int intProduct = multiply(int1, int2);
    string stringProduct1 = multiply(string1, int1);
    string stringProduct2 = multiply(string2, int2);

    //Displaying Results

    cout << int1 << " + " << int2 << " = " << intSum << endl
         << string1 << " + " << string2 << " = " << stringSum << endl
         << int1 << " * " << int2 << " = " << intProduct << endl
         << string1 << " * " << int1 << " = " << stringProduct1 << endl
         << string2 << " * " << int2 << " = " << stringProduct2 << endl;

    return 0;
}

string multiply(string stringGiven, int intGiven)
{
    string product = "";
    for (int i = 0; i < intGiven; i++)
    {
        product += stringGiven;
    }
    return product;
}

int multiply(int int1, int int2)
{
    int product = 0;
    product = int1 * int2;
    return product;
}

string add(string string1, string string2)
{
    string sum = "";
    sum = string1 + string2;
    return sum;
}

int add(int int1, int int2)
{
    int sum = 0;
    sum = int1 + int2;
    return sum;
}

string getStringInput(string prompt)
{
    string stringReadIn = "";

    cout << prompt;
    
    getline(cin, stringReadIn);
    cout << endl;

    return stringReadIn;
}

int getIntInput(string prompt, int MIN, int MAX)
{
    int numReadIn = 0;
    bool checkFail = false;

    do
    {
        cout << prompt;
        cin >> numReadIn;
        cout << endl;
        checkFail = checkFailure(numReadIn, MIN, MAX);
    } while (checkFail || numReadIn < MIN || numReadIn > MAX);

    return numReadIn;
}

bool checkFailure(int numReadIn, int MIN, int MAX)
{
    bool flag = false;
    flag = cin.fail();

    if (flag || numReadIn < MIN || numReadIn > MAX)
    {
        cout << "Error: Invalid Input!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return flag;
}
