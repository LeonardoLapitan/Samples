/*
 Name: Leonardo Lapitan, 2001158908, CS135 1007, Lab5A
 Description: A do...while loop must be used to take in input. A for loop must be used to output the first triangle. A while loop must be
used to output the second triangle.
 Input: Enter a count between 2 and 20
**4
Output:****
***
**
*
*
**
***
****
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int triangle = 0;
	bool triFlag = false;

	do
	{
		cout << "Enter a count between 2 and 20" << endl
			 << "**";
		cin >> triangle;
		cout << endl;

		if (triangle < 2 || triangle > 20)
		{
			cout << "Error: Invalid entry, please retry" << endl;

			triFlag = cin.fail();
			if (triFlag)
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	} while (cin.fail() || triangle < 2 || triangle > 20);

	for (int i = triangle; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	int triHeight = 0;

	while (triHeight < triangle)
	{
		int triWidth = 0;

		while (triWidth <= triHeight)
		{
			cout << "*";
			triWidth++;
		}
		cout << endl;
		triHeight++;
	}

	return 0;
}
