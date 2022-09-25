/*
 Name: Leonardo Lapitan, 2001158908, CS135 1007, CSShopAssignment4
 Description: In this section you will learn, in C++,
  how to use arrays, pass and use command line arguments, use the
<fstream> library, read from files into arrays, .
Input: ./a.exe s4-1.csv
Output: Number of rows read in: 8
Printing Customer #1's receipt.
Printing Customer #2's receipt.
Print sales summary? (Y/y) for yes, any other key for no: y
Printing sales report to summary.txt...
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

const double TAX_RATE = 0.0825;
const int MAX_ITEMS = 1000;
const int MAX_TRANSACTIONS = 100;

void printHeader();

/*
    main: Designated start of the program.
    parameters: argument count, array of command line args
    return value: Exit status
*/
int main(int argc, char const *argv[])
{
    ifstream iFile;
    ofstream oFile;

    // 4.1 TODO: - Open file name passed in argv
    //           - Error and exit if unable to open
    //           - Usage error if invalid argc

    if (argc != 2)
    {
        cout << "Usage: ./a.out <file name>" << endl;
        return 0;
    }

    iFile.open(argv[1]);
    if (!iFile.is_open())
    {
        cout << "Error: Invalid File Name.";
        return 0;
    }

    // 4.2 TODO: - Read from file into arrays using eof while loop:
    //             - first column:  ids
    //             - second column: names
    //             - third column:  costs
    //             - fourth column: qtys
    //             - fifth column:  paymentTypes
    //             - sixth column:  payments

    string line = "";
    int itemCnt = 0;
    int ids[MAX_ITEMS], qtys[MAX_ITEMS];
    double costs[MAX_ITEMS], subtotals[MAX_TRANSACTIONS],
        taxes[MAX_TRANSACTIONS], totals[MAX_TRANSACTIONS];
    string names[MAX_ITEMS], paymentTypes[MAX_ITEMS];
    string payments[MAX_ITEMS];

    while (!iFile.eof())
    {
        getline(iFile, line);

        int commaLoc = line.find(',');
        string data = line.substr(0, commaLoc);
        ids[itemCnt] = stoi(data);
        line = line.substr(commaLoc + 1, line.length());

        commaLoc = line.find(',');
        data = line.substr(0, commaLoc);
        names[itemCnt] = data;
        line = line.substr(commaLoc + 1, line.length());

        commaLoc = line.find(',');
        data = line.substr(0, commaLoc);
        costs[itemCnt] = stod(data);
        line = line.substr(commaLoc + 1, line.length());

        commaLoc = line.find(',');
        data = line.substr(0, commaLoc);
        qtys[itemCnt] = stoi(data);
        line = line.substr(commaLoc + 1, line.length());

        commaLoc = line.find(',');
        data = line.substr(0, commaLoc);
        paymentTypes[itemCnt] = data;
        line = line.substr(commaLoc + 1, line.length());

        payments[itemCnt] = line;

        itemCnt++;
    }

    // 4.2 TODO: - Print amount of items read in

    cout << "Number of rows read in: " << itemCnt << endl
         << endl;

    printHeader();

    int start = 0, end = 0, currentID = 0, transactionCnt = 0;

    // 4.3 TODO: Code section 4.3 in this while loop
    while (end < itemCnt)
    {
        cout << "Printing Customer #" << ids[end] << "'s receipt.\n";
        // 4.3 TODO: Get start and end point in parallel array

        start = end;
        currentID = ids[start];

        while (ids[end] == currentID)
        {
            end++;
        }
        // 4.3 TODO: Calculate subtotal, tax, and total and store
        //           the 3 calculations in their respective arrays.

        for (int i = start; i < end; i++)
        {
            subtotals[transactionCnt] += costs[i] * qtys[i];
        }

        taxes[transactionCnt] =
            ceil(subtotals[transactionCnt] * TAX_RATE * 100) / 100;
        totals[transactionCnt] =
            taxes[transactionCnt] + subtotals[transactionCnt];

        // 4.3 TODO: Print cash or card receipts to files.

        oFile.open("receipt_" + to_string(currentID) + ".txt");
        oFile << fixed << setprecision(2);
        oFile << setfill(' ');
        oFile << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/"
              << "\\/\\/\\/\\/\\/\\/\\/"
              << "\\/\\\n"
              << "|                                      |\n"
              << "|             UNLV CS Shop             |\n"
              << "|         4505 S Maryland Pkwy         |\n"
              << "|          Las Vegas,NV 89154          |\n"
              << "|            (702) 895-3011            |\n"
              << "|                                      |\n";

        for (int i = start; i < end; i++)
        {
            oFile << "| " << left << setw(15) << names[i] << right
                  << setw(17) << costs[i] << " x " << qtys[i] << " |"
                  << endl;
        }

        if (paymentTypes[transactionCnt - 1] == "cash")
        {
            cout << "cash: " << payments[itemCnt] << endl;
        }
        else
        {

            cout << "card: " << payments[transactionCnt] << endl;

        }

        oFile << "|                                      |\n"
              << "| Subtotal" << setw(28)
              << subtotals[transactionCnt] << " |" << endl
              << "| Tax Rate" << setw(30) << "  8.25% |" << endl
              << "| Tax     " << setw(28)
              << taxes[transactionCnt] << " |" << endl
              << "| Total   " << setw(28)
              << totals[transactionCnt] << " |" << endl
              << "|                                      |\n";



        oFile << "|                                      |\n"
              << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/"
              << "\\/\\/";

        oFile.close();
        transactionCnt++;
    }

    // 4.4 TODO: Prompt for summary/print summary if user wants summary.

    char summary = 0;
    cout << "Print sales report? "
         << "(Y/y) for yes, any other key for no: ";
    cin >> summary;

    int mindex = 0, maxdex = 0, totalItems = 0;
    double totalSubtotals = 0.0, totalTaxes = 0.0, totalTotals = 0.0;
    double avgPretax = 0.0, avgPosttax = 0.0;

    switch (summary)
    {

    case 'Y':
    case 'y':
    {

        oFile.open("summary.txt");
        cout << endl
             << "Printing sales report to summary.txt..." << endl;

        for (int i = 0; i < transactionCnt; i++)
        {
            totalSubtotals += subtotals[i];
            totalTaxes += taxes[i];
            totalTotals += totals[i];
            totalItems += qtys[i];

            if (totals[i] < totals[mindex])
            {
                mindex = i;
            }

            if (totals[i] > totals[maxdex])
            {
                maxdex = i;
            }
        }

        avgPretax = ceil(totalSubtotals / transactionCnt * 1000) / 1000;
        avgPosttax = ceil(totalTotals / transactionCnt * 1000) / 1000;

        oFile << "+" << setfill('-') << setw(62) << '-' << "+" << endl
              << "| " << left << setfill('.')
              << setw(40) << "Total Transactions"
              << right << setw(20) << transactionCnt << " |" << endl
              << "| " << left << setw(40) << "Total Number of Items Sold"
              << right << setw(20) << totalItems << " |" << endl
              << "| " << left << setfill(' ') << setw(40) << " "
              << right << setw(20) << " "
              << " |" << endl
              << "| " << left << setfill('.')
              << setw(40) << "Total Pre-tax Sales"
              << right << setw(20) << totalSubtotals << " |" << endl
              << "| " << left << setw(40) << "Total Taxes Charged"
              << right << setw(20) << totalTaxes << " |" << endl
              << "| " << left << setw(40) << "Total Post-tax Sales"
              << right << setw(20) << totalTotals << " |" << endl
              << "| " << setfill(' ') << setw(40) << " "
              << right << setw(20) << " "
              << " |" << endl
              << "| " << left << setfill('.')
              << setw(40) << "Average Pre-tax Sale"
              << right << setw(20) << avgPretax << " |" << endl
              << "| " << left << setw(40) << "Average Post-tax Sale"
              << right << setw(20) << avgPosttax << " |" << endl
              << "| " << setfill(' ') << left << setw(40) << " "
              << right << setw(20) << " "
              << " |" << endl
              << "| " << setfill('.') << left
              << setw(40) << "Lowest Sale ID"
              << right << setw(20) << mindex << " |" << endl
              << "| " << left << setw(40) << "Lowest Sale Subtotal"
              << right << setw(20) << subtotals[mindex] << " |" << endl
              << "| " << left << setw(40) << "Lowest Sale Tax"
              << right << setw(20) << taxes[mindex] << " |" << endl
              << "| " << left << setw(40) << "Lowest Sale Total"
              << right << setw(20) << totals[mindex] << " |" << endl
              << "| " << setfill(' ') << left << setw(40) << " "
              << right << setw(20) << " "
              << " |" << endl
              << "| " << setfill('.')
              << left << setw(40) << "Highest Sale ID"
              << right << setw(20) << maxdex << " |" << endl
              << "| " << left << setw(40) << "Highest Sale Subtotal"
              << right << setw(20) << subtotals[maxdex] << " |" << endl
              << "| " << left << setw(40) << "Highest Sale Tax"
              << right << setw(20) << taxes[maxdex] << " |" << endl
              << "| " << left << setw(40) << "Highest Sale Total"
              << right << setw(20) << totals[maxdex] << " |" << endl
              << "+" << setfill('-') << setw(62) << '-' << "+" << endl;

        oFile.close();
        break;
    }
    default:
    {
        cout << endl;
        cout << "exiting program without sales report...";
        return 0;
    }
    }
    return 0;
}

/*
    printHeader: Prints program header.
    parameters: none
    return value: none
*/
void printHeader()
{
    cout << "+" << setfill('-') << setw(77) << '-' << "+ \n"
         << "|    UU     UU  NNNN     NN  LL       VV      VV    "
         << "     CCCCCC    SSSSSSSS   | \n"
         << "|   /UU    /UU /NN/NN   /NN /LL      /VV     /VV    "
         << "    CC////CC  SS//////    | \n"
         << "|   /UU    /UU /NN//NN  /NN /LL      /VV     /VV    "
         << "   CC    //  /SS          | \n"
         << "|   /UU    /UU /NN //NN /NN /LL      //VV    VV     "
         << "  /CC        /SSSSSSSSS   | \n"
         << "|   /UU    /UU /NN  //NN/NN /LL       //VV  VV      "
         << "  /CC        ////////SS   | \n"
         << "|   /UU    /UU /NN   //NNNN /LL        //VVVV       "
         << "  //CC    CC        /SS   | \n"
         << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL   //VV        "
         << "   //CCCCCC   SSSSSSSS    | \n"
         << "|    ///////   //      ///  ////////     //         "
         << "    //////   ////////     | \n"
         << "|" << setfill(' ') << setw(77) << ' ' << "| \n"
         << "|                  SSSSSSSS  HH      HH    OOOOOOO  "
         << "  PPPPPPP                 | \n"
         << "|                 SS//////  /HH     /HH   OO/////OO "
         << " /PP////PP                | \n"
         << "|                /SS        /HH     /HH  OO     //OO"
         << " /PP   /PP                | \n"
         << "|                /SSSSSSSSS /HHHHHHHHHH /OO      /OO"
         << " /PPPPPPP                 | \n"
         << "|                ////////SS /HH//////HH /OO      /OO"
         << " /PP////                  | \n"
         << "|                       /SS /HH     /HH //OO     OO "
         << " /PP                      | \n"
         << "|                 SSSSSSSS  /HH     /HH  //OOOOOOO  "
         << " /PP                      | \n"
         << "|                ////////   //      //    ///////   "
         << " //                       | \n"
         << "+" << setfill('-') << setw(77) << '-' << "+ \n"
         << setfill(' ');
}
