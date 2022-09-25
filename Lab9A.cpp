/*
 Name: Leonardo Lapitan, 2001158908, CS135 1007, Lab9A
 Description: In this lab you will practice using basic input/output,
  user defined functions, and pass by value and pass by reference.
Input: Enter double between 0.500000 and 20.500000
**3

Enter another double between 0.500000 and 20.500000
**7
Output: 3.00 + 7.00 = 10.00
3.00 - 7.00 = -4.00
3.00 * 7.00 = 21.00
3.00 / 7.00 = 0.43
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

double getDoubleInput(string, double, double);
bool checkFailure(double, double, double);
void getDoubleInputs(double &, double &);
void addSubtract(double &, double &);
void multiplyDivide(double &, double &);

int main()
{
    double num1 = 0.0, num2 = 0.0;

    cout << fixed << setprecision(2);
    getDoubleInputs(num1, num2);
    addSubtract(num1, num2);
    multiplyDivide(num1, num2);

    return 0;
}

void addSubtract(double &num1, double &num2)
{
    double add = 0.0, subtract = 0.0;

    add = num1 + num2;

    cout << num1 << " + " << num2 << " = " << add << endl;

    subtract = num1 - num2;

    cout << num1 << " - " << num2 << " = " << subtract << endl;
}

void multiplyDivide(double &num1, double &num2)
{

    double multiply = 0.0, divide = 0.0;

    multiply = num1 * num2;

    cout << num1 << " * " << num2 << " = " << multiply << endl;

    divide = num1 / num2;

    cout << num1 << " / " << num2 << " = " << divide << endl;
}

void getDoubleInputs(double &input1, double &input2)
{
    // Minimums/maximums
    const double MIN = 0.500000;
    const double MAX = 20.500000;
    // Prompt for double input
    string prompt1 = "Enter double between " +
                     to_string(MIN) + " and " +
                     to_string(MAX) + "\n**";
    // Prompt for second double input
    string prompt2 = "Enter another double between " +
                     to_string(MIN) + " and " +
                     to_string(MAX) + "\n**";

    input1 = getDoubleInput(prompt1, MIN, MAX);
    input2 = getDoubleInput(prompt2, MIN, MAX);
}

double getDoubleInput(string prompt, double MIN, double MAX)
{
    double numReadIn = 0.0;
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

bool checkFailure(double numReadIn, double MIN, double MAX)
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
